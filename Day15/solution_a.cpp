#include <iostream>
#include <vector>
#include <unordered_map>

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

      if (map[row][col] == 'O') {
        int temp_r = row;
        int temp_c = col;
        
        bool empty = false;
        while(valid(map, temp_r, temp_c)) {
          if (map[temp_r][temp_c] == '.') {
            empty = true;
            break;
          }
          temp_r += rx;
          temp_c += cx;
        }

        if (empty) {
          map[row][col] = '.';
          map[temp_r][temp_c] = 'O';
        } else {
          row -=rx;
          col -= cx;
        }
      }
    }
  }
}

int main() {
  std::vector<std::string> map;
  std::string dir = "";
  std::string line;
  
  bool d = false;
  bool start = false;
  int start_r = -1;
  int start_c = 0;

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
    if (!start) {
      for (int i = 0; i < line.size(); i++) {
        if (line[i] == '@') {
          start_c = i;
          start = true;
          break;
        }
      }
      start_r++;
    }
  }
  map[start_r][start_c] = '.';
  moveRobot(map, dir, start_r, start_c);

  unsigned long long total = 0;
  for (int i = 1; i < map.size()-1; i++) {
    for (int j = 1; j < map[0].size()-1; j++) {
      if (map[i][j] == 'O') total += (i*100) + j;
    }
  }
  std::cout << total << std::endl;
}
