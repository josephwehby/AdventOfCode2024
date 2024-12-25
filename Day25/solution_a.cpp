#include <iostream>
#include <vector>
#include <set>

std::vector<int> parse() {
  std::vector<int> pins(5, 0);
  std::string line;

  for (int i = 0; i < 5; i++) {
    std::getline(std::cin, line);
    for (int i = 0; i < 5; i++) {
      pins[i] += (line[i] == '#') ? 1 : 0;
    }
  }
  
  std::getline(std::cin, line);
  std::getline(std::cin, line);
  return pins;
}

bool match(std::vector<int>& lock, std::vector<int>& key) {
  for (int i = 0; i < lock.size(); i++) {
    if (key[i] + lock[i] > 5) return false;
  }

  return true;
}

int main() {
  std::string line;
  std::set<std::vector<int>> keys;
  std::set<std::vector<int>> locks;
  
  bool key = true;
  while (std::getline(std::cin, line)) {
    if (line == "#####") key = false;
    if (line == ".....") key = true;

    if (key) {
      keys.insert(parse()); 
    } else {
      locks.insert(parse()); 
    }
  }
  
  int unique = 0;
  for (auto lock : locks) {
    for (auto key : keys) { 
      if (match(lock, key)) unique++; 
    }
  }

  std::cout << unique << std::endl;
}
