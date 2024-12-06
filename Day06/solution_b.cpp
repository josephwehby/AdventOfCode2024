#include <iostream>
#include <vector>
#include <map>

bool checkValid(std::vector<std::string>& map, int row, int col) {
  if (map[row][col] == '#') return false;
  return true;
}

bool isLoop(std::vector<std::string>& map, int row, int col) {
  int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};  
  int facing = 0;
  std::multimap<int,int> seen;

  while (true) {
    int rx = dir[facing][0];
    int cx = dir[facing][1];
    if (row+rx < 0 || row+rx >= map.size() || col+cx < 0 || col+cx >= map[0].size()) break;
    if (checkValid(map, row+rx, col+cx)) {
      row += rx;
      col += cx;
      int index = row * map[0].size() + col;
      auto range = seen.equal_range(index);
      for (auto it = range.first; it != range.second; ++it) {
        if (it->second == facing) return true;
      }

      seen.insert({index, facing});  
    } else {
      facing = (facing+1)%4;
     }
  }

  return false;
}

int main() {
  std::string line;
  std::vector<std::string> map;
  std::vector<std::pair<int,int>> route;
  int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};  
  int facing = 0;
  int s_row, s_col, count;
  bool start = false;
  count = 0;

  while (getline(std::cin, line)) {
    map.push_back(line);
    if (start) continue;

    for (int i = 0; i < line.length(); i++) {
      if (line[i] == '^') {
        s_col = i;
        start = true;
        break;
      }
    }
    s_row = count; 
    count++;
  }

  int row = s_row;
  int col = s_col;
  // walk the route to get the oroiginal route
  while (true) {
    int rx = dir[facing][0];
    int cx = dir[facing][1];
    if (row+rx < 0 || row+rx >= map.size() || col+cx < 0 || col+cx >= map[0].size()) break;
    if (checkValid(map, row+rx, col+cx)) {
      row += rx;
      col += cx;
      if (map[row][col] != 'X') route.push_back({row, col});
      map[row][col] = 'X';
    } else {
      facing = (facing+1)%4;
    }
  }
  
  // check potential paths
  count = 0;
  for (auto block : route) {
    map[block.first][block.second] = '#';
    if (isLoop(map, s_row, s_col)) {
      count++;
    }
    map[block.first][block.second] = '.';
  }

  std::cout << count << std::endl;
  return 0;
}
