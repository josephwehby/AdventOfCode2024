#include <iostream>
#include <regex>

int main() {
  std::regex reg("mul\\(([0-9]+),([0-9]+)\\)");
  
  std::string line;
  long long total = 0;
  while(getline(std::cin, line)) {
    std::smatch m;
    std::sregex_iterator begin(line.begin(), line.end(), reg);
    std::sregex_iterator end;

    for (auto it = begin; it != end; it++) {
      std::smatch match = *it;
      int first = std::stoi(match[1].str());
      int second = std::stoi(match[2].str());
      total += (first*second); 
    }
  }

  std::cout << total << std::endl;
  return 0;
}
