#include <iostream>
#include <vector>
#include <deque>

bool valid(std::vector<std::string>& grid, int row, int col) {
  if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) return false;
  if (grid[row][col] == '#') return false;
  return true;
}

int bfs(std::vector<std::string>& grid, std::pair<int,int> start, std::pair<int,int> end) {
  int ROWS = grid.size();
  int COLS = grid[0].size();
  int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  std::deque<std::pair<int,int>> q;
  std::vector<int> distance(ROWS*COLS, -1);
  std::vector<bool> visited(ROWS*COLS, false);
  
  q.push_back(start);
  distance[start.first * COLS + start.second] = 0;
  visited[start.first * COLS + start.second] = false;
  while (!q.empty()) {
    auto node = q.front();

    for (auto d : dirs) {
      int rx = node.first + d[0];
      int cx = node.second + d[1];
      if (valid(grid, rx, cx) && !visited[rx * COLS + cx]) {
        distance[rx * COLS + cx] = distance[node.first * COLS + node.second] + 1;
        visited[rx * COLS + cx] = true;
        q.push_back({rx, cx});
      }
    }

    q.pop_front();
  }

  return distance[end.first * COLS + end.second];
}

int main() {
  std::vector<std::string> grid;
  std::string line;
  
  std::pair<int,int> start;
  std::pair<int,int> end;

  int row = 0;
  while (std::getline(std::cin, line)) {
    grid.push_back(line);
    for (int i = 0; i < line.size(); i++) {
      
      if (line[i] == 'S') {
        start = {row, i};
        grid[row][i] = '.';
      }

      if (line[i] == 'E') {
        end = {row, i};
        grid[row][i] = '.';
      }

    }
    row++;
  }

  std::cout << bfs(grid, start, end) << std::endl;
}
