#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

bool check(std::vector<std::string>& map, std::pair<int,int> point) {
  if (point.first < 0 || point.first >= map.size() || point.second < 0 || point.second >= map[0].size()) return false;
  return true;
}

void genAntinode(std::pair<int,int> p1, std::pair<int,int> p2, std::vector<std::string>&map, std::set<int>& all) {
  int drow = p2.first - p1.first;
  int dcol = p2.second - p1.second;
  int index = 0;

  while (true) {
    int r = p1.first - drow*index;
    int c = p1.second - dcol*index;
    if (check(map, {r, c})) {
      all.insert(r*map[0].size() + c);
    } else {
       break;
    }
    index++;
  }
  
  index = 0;
  while (true) {
    int r = p2.first + drow*index;
    int c = p2.second + dcol*index;
    if (check(map, {r, c})) {
      all.insert(r*map[0].size() + c);
    } else {
       break;
    }
    index++;
  }
}

int main() {
  std::vector<std::string> map;
  std::unordered_map<char, std::vector<std::pair<int,int>>> points;
  std::set<int> all;
  std::string line;

  int row = 0;
  while (getline(std::cin, line)) {
    map.push_back(line);
    for (int c = 0; c < line.size(); c++) {
      if (line[c] != '.') {
        points[line[c]].push_back({row, c});
      } 
    }
    row++;
  }

  for (auto mit : points) {
    for (int i = 0; i < mit.second.size(); i++) {
      for (int j = i+1; j < mit.second.size(); j++) {
        genAntinode(mit.second[i], mit.second[j], map, all); 
      }
    }
  }

  std::cout << all.size() << std::endl;
}
