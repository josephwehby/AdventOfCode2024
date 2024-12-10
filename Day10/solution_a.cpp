#include <iostream>
#include <vector>
#include <set>

bool valid(int row, int col, char num, std::vector<std::string>& map) {
  if (row < 0 || col < 0 || row >= map.size() || col >= map[0].size()) return false;
  if ((char)(num+1) != map[row][col]) return false;
  return true;
}

int dfs(std::vector<std::string>& map, int row, int col, std::set<int>& visited) {
  if (map[row][col] == '9') {
    int index = row*map[0].size() + col;
    if (visited.find(index) == visited.end()) {
      visited.insert(index);
      return 1;
    } else {
      return 0;
    }
  }

  int dir[4][2] = {{0,1}, {0,-1}, {-1, 0}, {1,0}};
  int count = 0;
  
  for (auto d : dir) {
    int n_row = row + d[0];
    int n_col = col + d[1];

    if (valid(n_row, n_col, map[row][col], map)) {
      count += dfs(map, n_row, n_col, visited);
    }
  }

  return count;
}

int main(){
  std::vector<std::string> map;
  std::vector<std::pair<int, int>> trail_heads;
  std::string line;

  int row = 0;
  while (getline(std::cin, line)) {
    map.push_back(line);
    for (int c = 0; c < line.length(); c++) {
      if (line[c] == '0') trail_heads.push_back({row, c});
    }
    row++;
  }
  
  int total = 0;
  for (auto p : trail_heads) {
    std::set<int> visited;
    total += dfs(map, p.first, p.second, visited);
  }

  std::cout << total << std::endl;
  
}
