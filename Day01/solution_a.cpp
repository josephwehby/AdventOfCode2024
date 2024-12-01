#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
  
  std::string line;
  std::stringstream ss;
  std::vector<int> left;
  std::vector<int> right;

  while (getline(std::cin, line)) {
    int first, second;
    ss << line;
    ss >> first >> second;
    left.push_back(first);
    right.push_back(second);
    ss.clear();
  }

  sort(left.begin(), left.end());
  sort(right.begin(), right.end());
  
  long result = 0;
  for (int i = 0; i < left.size(); i++) {
    result += std::abs(left[i] - right[i]);
  }

  std::cout << result << std::endl;
  
  return 0;
}
