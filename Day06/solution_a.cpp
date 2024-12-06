#include <iostream>
#include <vector>

bool checkValid(std::vector<std::string>& map, int row, int col) {
  if (map[row][col] == '#') return false;

  return true;
}

int main() {
  std::string line;
  std::vector<std::string> map;
  int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};  
  int facing = 0;
  int row, col, count;
  bool start = false;
  count = 0;

  while (getline(std::cin, line)) {
    map.push_back(line);
    if (start) continue;

    for (int i = 0; i < line.length(); i++) {
      if (line[i] == '^') {
        col = i;
        start = true;
        break;
      }
    }
    row = count; 
    count++;
  }

  
  // walk the route and replace visited spots with an X
  count = 1;
  map[row][col] = 'X';
  
  while (true) {
    int rx = dir[facing][0];
    int cx = dir[facing][1];
    if (row+rx < 0 || row+rx >= map.size() || col+cx < 0 || col+cx >= map[0].size()) break;
    if (checkValid(map, row+rx, col+cx)) {
      row += rx;
      col += cx;
      if (map[row][col] != 'X') count++;
      map[row][col] = 'X';
    } else {
      facing = (facing+1)%4;
    }
  }

  std::cout << count << std::endl;
  return 0;
}
