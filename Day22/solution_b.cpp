#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <tuple>

unsigned long long generate(unsigned long long secret) {
  unsigned long long result;

  result = secret * 64;
  secret = (secret ^ result) % 16777216;
  result = secret / 32;
  secret = (secret ^ result) % 16777216;
  result = secret * 2048;
  secret = (secret ^ result) % 16777216;
  
  return secret;
}

void maxSeq(std::vector<unsigned long long>& nums, std::vector<int>& changes, std::map<std::tuple<int,int,int,int>, unsigned long long>& vals) {
  std::set<std::tuple<int,int,int,int>> checked;

  for (int i = 0; i <= 1996; i++) {
    auto window = std::make_tuple(changes[i], changes[i+1], changes[i+2], changes[i+3]);
    if (checked.find(window) == checked.end()) {
      vals[window] += (nums[i+4]);
      checked.insert(window);
    }
  }

}

int main() {
  std::string line;
  std::map<std::tuple<int,int,int,int>, unsigned long long> vals; 

  while (std::getline(std::cin, line)) {
    
    unsigned long long secret = std::stoull(line);
    std::vector<unsigned long long> nums;
    std::vector<int> changes;
    
    nums.push_back(secret%10);
    for (int i = 0; i < 2000; i++) {
      secret = generate(secret);
      nums.push_back(secret%10);
    }

    for (int i = 1; i <= 2000; i++) {
      changes.push_back(nums[i] - nums[i-1]);
    }
    maxSeq(nums, changes, vals);
  }

  unsigned long long max = 0;
  
  for (auto v : vals) {
    if (v.second > max) {
      max = v.second;
    }
  }

  std::cout << max << " " << std::endl;
  return 0;
}
