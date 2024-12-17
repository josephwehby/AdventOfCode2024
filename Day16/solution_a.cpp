#include <iostream>
#include <vector>
#include <map>
#include <tuple>

bool valid(std::vector<std::string>& grid, int row, int col) {
  if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) return false;
  if (grid[row][col] == '#') return false;

  return true;
}

int dijkstra(std::vector<std::string>& grid, std::pair<int, int> start, std::pair<int,int> end) {
  int ROWS = grid.size();
  int COLS = grid[0].size();
  int dirs[4][2] = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};

  std::multimap<int,std::tuple<int, int, int>> nodes;
  std::map<std::tuple<int,int, int>, int> distances;

  nodes.insert({0, {start.first, start.second, 0}});
  distances[{start.first, start.second, 0}] = 0;

  while (!nodes.empty()) {
    auto node = nodes.begin();
    auto [r, c, d] = node->second;
    int node_cost = node->first;
    nodes.erase(node);
    if (grid[r][c] == 'E') return node->first;

    // forward
    int nr = r + dirs[d][0];
    int nc = c + dirs[d][1];
    if (valid(grid, nr, nc)) {
      int cost = node_cost + 1;
      if (distances.find({nr, nc, d}) == distances.end() || cost < distances[{nr, nc, d}]) {
        distances[{nr, nc, d}] = node_cost;
        nodes.insert({cost, {nr, nc, d}});
      }
    }

    // left 90
    int ndir = (d+1)%4;
    int cost = node_cost + 1000;
    if (distances.find({r, c, ndir}) == distances.end() || cost < distances[{r, c, ndir}]) {
      distances[{r, c, ndir}] = cost;
      nodes.insert({cost, {r ,c, ndir}});
    }

    // right 90
    ndir = (d+3)%4;
    cost = node_cost + 1000;
    if (distances.find({r, c, ndir}) == distances.end() || cost < distances[{r, c, ndir}]) {
      distances[{r, c, ndir}] = cost;
      nodes.insert({cost, {r ,c, ndir}});
    }

  }

  return -1;
}

int main() {
  std::vector<std::string> grid;
  std::string line;
  
  std::pair<int,int> start;
  std::pair<int,int> end;
  
  int row = 0;
  while (std::getline(std::cin, line)) {
    grid.push_back(line);
    for (int c = 0; c < line.size(); c++){
      if (line[c] == 'E') end = {row, c};
      if (line[c] == 'S') start = {row, c};
    }
    row++;
  }
  std::cout << dijkstra(grid, start, end) << std::endl;
  return 0;
}
