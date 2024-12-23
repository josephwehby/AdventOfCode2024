#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <unordered_map>
#include <algorithm>

bool check(std::unordered_map<std::string, std::set<std::string>> graph, std::string f, std::string s) {
  auto mit = graph.find(f);
  for (std::string t : mit->second) {
    if (t == s) return true;
  }
  return false;
}

int main() {
  std::string line;
  std::unordered_map<std::string, std::set<std::string>> graph;
  std::set<std::set<std::string>> visited;

  while (std::getline(std::cin, line)) {
    std::string n1, n2;
    std::stringstream ss(line);
    std::getline(ss, n1, '-');
    std::getline(ss, n2, '-');
    
    graph[n1].insert(n2);
    graph[n2].insert(n1); 
  }

  unsigned int total = 0;
  for (auto mit : graph) {
    for (auto f : mit.second) {
      for (auto s : mit.second) {
        if (s == f) continue;
        if (f[0] != 't' && s[0] != 't' && mit.first[0] != 't') continue;
        if (check(graph, f, s)) {
          std::set<std::string> temp = {mit.first, f, s};
          if (visited.find(temp) == visited.end()) {
            total++;
            visited.insert(temp);
          }
        } 
      }
    }
  }

  std::cout << total << std::endl;
}
