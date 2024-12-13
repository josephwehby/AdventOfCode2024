#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <climits>
#include "BigInteger.hpp"

int main() {
  std::string nums;
  std::string line;

  while (std::getline(std::cin, line)) {
    nums = line;
  }

  std::unordered_map<std::string, BigInt> stones;
  
  std::string token;
  char delimiter = ' ';
  std::stringstream ss(nums);
  while (std::getline(ss, token, delimiter)) stones[token] = stones[token] + 1;

  for (int i = 0; i < 75; i++) {
    std::unordered_map<std::string, BigInt> new_stones;
    for (auto mit : stones) {
      
      std::string val = mit.first;
      BigInt stone_count = mit.second;

      if (val == "0") {
        new_stones["1"] = new_stones["1"] + stone_count;

      } else if (val.size()%2 == 0) {
        int mid = val.size()/2;
        std::string first = val.substr(0, mid);
        std::string end = val.substr(mid);
        
        new_stones[first] = new_stones[first] + stone_count;
        end.erase(0, end.find_first_not_of('0'));
        if (end.empty()) end = "0";
        new_stones[end] = new_stones[end] + stone_count;

      } else {
        unsigned long long updated = std::stoull(val) * 2024;
        std::string s = std::to_string(updated);
        new_stones[s] = new_stones[s] + stone_count;
      }
      
    }

    stones = std::move(new_stones);
  }


  BigInt total = 0;
  for (auto p : stones) total = total + p.second;

  std::cout << total << std::endl;
  return 0;
}
