#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

int main() {
  std::string nums;
  std::string line;

  while (std::getline(std::cin, line)) {
    nums = line;
  }

  std::vector<std::string> stones;
  
  std::string token;
  char delimiter = ' ';
  std::stringstream ss(nums);
  while (std::getline(ss, token, delimiter)) stones.push_back(token);

  for (int i = 0; i < 25; i++) {
    int size = stones.size();

    for (int j = 0; j < size; j++) {
      auto s = stones[j];
      if (s == "0") {
        stones[j] = "1";
      } else if (s.size()%2 == 0) {
        int mid = s.size()/2;
        std::string end = s.substr(mid);
        if (end[0] == '0') {
          unsigned long long e = std::stoull(end);
          stones.push_back(std::to_string(e));
        } else {
          stones.push_back(end);
        }
        stones[j] = s.substr(0, mid);
      } else {
        unsigned long long n = 2024 * std::stoull(s);
        stones[j] = std::to_string(n);
      }
    }
  }
  
  std::cout << stones.size() << std::endl;
  return 0;
}
