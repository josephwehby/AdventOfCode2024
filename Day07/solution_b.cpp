#include <iostream>
#include <vector>
#include <sstream>

bool checkValid(unsigned long long target, unsigned long long current, std::vector<unsigned long long> nums, int index) {
  if (current == target && index == nums.size()) return true;
  if (index >= nums.size()) return false;
  if (current > target) return false;

  bool mult = checkValid(target, current*nums[index], nums, index+1);
  bool add = checkValid(target, current+nums[index], nums, index+1);
  
  unsigned long long cat = std::stoull(std::to_string(current) + std::to_string(nums[index]));
  bool concat = checkValid(target, cat, nums, index+1);

  return mult || add || concat;
}

int main() {
  unsigned long long total = 0;
  std::string line;

  while(getline(std::cin, line)) {
    unsigned long long target, num;
    std::vector<unsigned long long> nums;
    std::stringstream ss;
    ss << line;
    ss >> target;
    ss.ignore();
    while (ss >> num) nums.push_back(num);
    if (checkValid(target, nums[0], nums, 1)) {
      total += target;
    }
  }

  std::cout << total << std::endl;
  return 0;
}
