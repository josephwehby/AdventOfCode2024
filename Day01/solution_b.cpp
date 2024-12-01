#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
  
  std::string line;
  std::stringstream ss;
  std::vector<int> left;
  std::unordered_map<int, int> right;

  while (getline(std::cin, line)) {
    int first, second;
    ss << line;
    ss >> first >> second;
    left.push_back(first);
    right[second] += 1;
    ss.clear();
  }

  long long result = 0;
  for (int n : left) {
    if (right.find(n) != right.end()) {
      result += (n * right[n]);
    }
  }

  std::cout << result << std::endl;
  
  return 0;
}
