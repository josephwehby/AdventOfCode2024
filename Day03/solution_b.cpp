#include <iostream>
#include <regex>

int main() {
  std::regex reg("do\\(\\)|don't\\(\\)|mul\\(([0-9]+),([0-9]+)\\)");
  
  std::string line;
  long long total = 0;
  bool dont = false;

  while(getline(std::cin, line)) {
    std::smatch m;
    std::sregex_iterator begin(line.begin(), line.end(), reg);
    std::sregex_iterator end;
    
    for (auto it = begin; it != end; it++) {
      std::string m = it->str();
      if (m == "do()") {
        dont = false;
        continue;
      }

      if (m == "don't()") {
        dont = true;
        continue;
      }
      
      if (!dont) {
        std::smatch match = *it;
        int first = std::stoi(match[1].str());
        int second = std::stoi(match[2].str());
        total += (first*second); 
      }
     
    }
  }

  std::cout << total << std::endl;
  return 0;
}
