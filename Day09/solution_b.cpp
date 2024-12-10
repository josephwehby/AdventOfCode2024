#include <iostream>
#include <vector>
#include <cstdint>
#include <unordered_map>

std::unordered_map<int,int> sizes;

std::vector<int16_t> expand(std::string& disk_map) {
  std::vector<int16_t> expanded;

  uint16_t id = 0;
  for (int i = 0; i < disk_map.size(); i+=2) {
    int block = disk_map[i] - '0';
    int free_space = (i+1 >= disk_map.size()) ? 0 : disk_map[i+1] - '0';
    for (int j = 0; j < block; j++) expanded.push_back(id);
    for (int j = 0; j < free_space; j++) expanded.push_back(-1);
    sizes[id] = block;
    id++;
  }

  return expanded;
}

void shift(std::vector<int16_t>& expanded) {
  int left = 0;
  int right = expanded.size()-1;
  

  
}

int main() {
  std::string line;
  std::string disk_map;
  while (getline(std::cin, line)) {
    disk_map = line;
  }

  auto expanded = expand(disk_map);
  shift(expanded);
  
  long long result = 0;
  for (int i = 0; i < expanded.size(); i++) {
    if (expanded[i] == -1) continue;
    result += (i * (int)expanded[i]);

  }
  std::cout << result << std::endl;
}
