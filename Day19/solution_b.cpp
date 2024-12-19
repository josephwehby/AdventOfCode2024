#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

unsigned long long isPossible(std::string line, std::string current, std::vector<std::string>& patterns, std::unordered_map<std::string, unsigned long long>& cache) {
  if (cache.find(current) != cache.end()) return cache[current];
  if (current == line) return 1;
  if (current.size() > line.size()) return 0;
  if (line.compare(0, current.size(), current) != 0) return 0;
  
  unsigned long long count = 0;
  for (auto p : patterns) {
    count += isPossible(line, current+p, patterns, cache);
  } 
  
  cache[current] = count;
  return cache[current];
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
  
  unsigned long long total = 0;
  while (std::getline(std::cin, line)) {
    if (line == "") continue;
    std::unordered_map<std::string, unsigned long long> cache;
    total += isPossible(line, "", patterns, cache);
  }

  std::cout << total << std::endl;
  return 0;
}
