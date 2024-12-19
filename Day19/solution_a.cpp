#include <iostream>
#include <vector>
#include <sstream>

bool isPossible(std::string line, std::string current, std::vector<std::string>& patterns) {
  if (line == "") return false;
  if (current == line) return true;
  if (current.size() > line.size()) return false;
  if (line.compare(0, current.size(), current) != 0) return false;

  for (auto p : patterns) {
    if (isPossible(line, current+p, patterns)) return true;
  } 

  return false;
}

int main() {
  std::vector<std::string> patterns;

  std::string line;
  std::getline(std::cin, line);
  
  std::stringstream ss(line);
  std::string pattern;
  while(std::getline(ss, pattern, ',')) {
    if (pattern[0] == ' ') {
      pattern.erase(0, 1);
    }
    patterns.push_back(pattern);
  }
  
  int total = 0;
  while (std::getline(std::cin, line)) {
    if (isPossible(line, "", patterns)) total++;
  }

  std::cout << total << std::endl;
  return 0;
}
