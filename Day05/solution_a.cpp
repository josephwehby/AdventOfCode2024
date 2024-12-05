#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <set>

int main() {
  std::string line;
  int total = 0;

  std::unordered_map<int, std::vector<int>> before;
  bool update = false;

  while (getline(std::cin, line)) {
    std::stringstream ss;
    int num, num1;
    
    if (line == "") {
      update = true;
      continue;
    }

    if (!update) {
      ss << line;
      ss >> num;
      ss.ignore();
      ss >> num1;
      before[num].push_back(num1); 
      continue;
    }
    
    std::set<int> seen;
    std::vector<int> nums;
    ss << line;
    bool valid = true;
    
    while (ss >> num) {
      seen.insert(num);
      nums.push_back(num);
      if (seen.size() == 0) continue;      

      auto bit = before.find(num);

      if (bit != before.end()) {
        for (int n : bit->second) {
          if (seen.find(n) != seen.end()) valid = false;
        }

      }
      if (!valid) break;
      ss.ignore();
    }

    if (valid) total += nums[nums.size()/2];
  }

  std::cout << total << std::endl;
  return 0;
}
