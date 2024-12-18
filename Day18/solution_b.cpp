#include <iostream> 
#include <vector>
#include <deque>
#include <sstream>

constexpr int ROWS = 71;
constexpr int COLS = 71;

bool valid(const std::vector<std::vector<char>>& grid, int row, int col) {
  if (row < 0 || col < 0 || row >= ROWS || col >= COLS) return false;
  if (grid[row][col] == '#') return false;
  return true;
}

int bfs(std::vector<std::vector<char>>& grid) {
  std::deque<std::pair<int,int>> q;
  std::vector<bool> visited(ROWS*COLS, false);
  std::vector<int> dist(ROWS*COLS, -1);
  int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  
  q.push_back({0,0});
  visited[0] = true;
  dist[0] = 0;
    

  while (!q.empty()) {
    auto node = q.front();
    int r = node.first;
    int c = node.second;


    for (auto d : dirs) {
      int nr = r + d[0];
      int nc = c + d[1];
      if (valid(grid, nr, nc) && visited[nr * COLS + nc] == false) {
        dist[nr * COLS + nc] = dist[r * COLS + c] + 1;
        visited[nr*COLS + nc] = true;
        q.push_back({nr, nc});
      }
    }

    q.pop_front();
  }
  
  return dist[70 * COLS + 70];
}

int main() {
  std::vector<std::vector<char>> grid(71, std::vector<char>(71, '.'));
  std::string line;
  
  while (std::getline(std::cin, line)) {
    int row, col;
    char junk;
    std::stringstream ss;     
    ss << line;
    ss >> col >> junk >> row;
    grid[row][col] = '#';
    if (bfs(grid) == -1) {
      std::cout << line << std::endl;
      break;
    }
  }
  
  return 0;
}
