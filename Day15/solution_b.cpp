#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <deque>

bool valid(std::vector<std::string>& map, int row, int col) {
  if (row < 0 || col < 0 || row >= map.size() || col >= map[0].size()) return false;
  if (map[row][col] == '#') return false;

  return true;
}

void moveRobot(std::vector<std::string>& map, std::string dir, int start_r, int start_c) {
  std::unordered_map<char, std::pair<int,int>> dirs = {
    {'<', {0, -1}}, {'>', {0, 1}}, {'^', {-1, 0}}, {'v', {1, 0}}
  };
  
  int row = start_r;
  int col = start_c;

  for (char d : dir) {
    int rx = dirs[d].first; 
    int cx = dirs[d].second; 
    
    if (valid(map, row+rx, col+cx)) {
      row+=rx;
      col+= cx;
      
      char block = map[row][col];
      if (block == '[' || block == ']') {
        std::deque<std::pair<int,int>> boxes;
        std::set<std::pair<int, int>> seen;
        bool possible = true; 
        
        boxes.push_back({row, col});
        seen.insert({row, col});
        
        if (block == ']') {
          boxes.push_back({row, col-1});
          seen.insert({row, col-1});
        } else {
          boxes.push_back({row, col+1});
          seen.insert({row, col+1});
        }

        while (!boxes.empty()) {
          auto bracket = boxes.front();
          
          int next_r = bracket.first + rx;
          int next_c = bracket.second + cx;
          char c = map[next_r][next_c];
          

          if (c == ']' && seen.find({next_r, next_c}) == seen.end()) {
            seen.insert({next_r, next_c});
            seen.insert({next_r, next_c-1});
            boxes.push_back({next_r, next_c-1});
            boxes.push_back({next_r, next_c});
          } else if (c == '[' && seen.find({next_r, next_c}) == seen.end()) {
            seen.insert({next_r, next_c});
            seen.insert({next_r, next_c+1});
            boxes.push_back({next_r, next_c+1});
            boxes.push_back({next_r, next_c}); 
          } else if (c == '#') {
            possible = false;
            break;
          } else {
      
          }

          boxes.pop_front();
        }

        // shift the boxes
        auto m = map;
        if (possible) {
          for (auto coords : seen) {
            map[coords.first][coords.second] = '.'; 
          }
          for (auto coords : seen) {
            int nr = coords.first + rx;
            int nc = coords.second + cx;
            map[nr][nc] = m[coords.first][coords.second];
          }

          map[row-rx][col-cx] = '.';
          map[row][col] = '@';
        } else {
          row -= rx;
          col -= cx;
        }
      } else {
        map[row-rx][col-cx] = '.';
        map[row][col] = '@';
      }
    }

  }
}

std::vector<std::string> expandMap(std::vector<std::string>& map) {
  std::vector<std::string> n_map;

  for (std::string line : map) {
    std::string row = "";
    for (char c : line) {
      if (c == '#') {
        row += "##";
      } else if (c == '.') {
        row += "..";
      } else if (c == 'O') {
        row += "[]";
      } else {
        row += "@.";
      }
    }
    n_map.push_back(row);
  }

  return n_map;
}

int main() {
  std::vector<std::string> map;
  std::string dir = "";
  std::string line;
  int start_r, start_c;  
  bool d = false;

  while (std::getline(std::cin, line)) {
    if (line == "") {
      d = true;
      continue;
    }

    if (d) {
      dir += line;
      continue;
    }
    
    map.push_back(line);  
  }
  
  map = expandMap(map);
  for (int i = 0; i < map.size(); i++) {
    for (int j = 0; j < map[0].size(); j++) {
      if (map[i][j] == '@') {
        start_r = i;
        start_c = j;
        break;
      }
    }
  }
  
  //map[start_r][start_c] = '.';
  moveRobot(map, dir, start_r, start_c);
  
  for (auto l : map) std::cout << l << std::endl;
  std::cout << std::endl;
  
  for (std::string row : map) std::cout << row << std::endl;
  unsigned long long total = 0;
  for (int i = 1; i < map.size()-1; i++) {
    for (int j = 1; j < map[0].size()-1; j++) {
      if (map[i][j] == '[') total += (i*100) + j;
    }
  }
  std::cout << total << std::endl;
}
