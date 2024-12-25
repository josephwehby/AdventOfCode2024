#include <iostream>
#include <unordered_map>
#include <sstream>
#include <list>
#include <string>

unsigned long long shift(std::unordered_map<std::string, int>& vals) {
  unsigned long long r = 0;

  for (auto v : vals) {
    std::string key = v.first;
    int val = v.second;
    if (key[0] != 'z') continue;
    
    std::string s = key.substr(1);
    int n = std::stoi(s);
    r |= (static_cast<unsigned long long>(val) << n);
  }

  return r;
}

unsigned long long run(std::unordered_map<std::string, int>& vals, std::list<std::string>& instructions) {
  while (instructions.size() > 0) {

    for (auto it = instructions.begin(); it != instructions.end();) {

      int r;
      std::stringstream ss(*it);
      std::string v1, op, v2, junk, result;
      ss >> v1 >> op >> v2 >> junk >> result;

      if (vals.find(v1) != vals.end() && vals.find(v2) != vals.end()) {
        if (op == "AND") {
          r = vals[v1] & vals[v2]; 
        } else if (op == "XOR") { 
          r = vals[v1] ^ vals[v2]; 
        } else {
          r = vals[v1] | vals[v2]; 
        }
        vals[result] = r;
        it = instructions.erase(it);
      } else {
        it++;
      }
    }
  }

  return shift(vals);
}

int main() {
  std::string line;
  std::unordered_map<std::string, int> vals;
  std::list<std::string> instructions;

  while (std::getline(std::cin, line)) {
    if (line == "") break;
    std::stringstream ss(line);
    std::string token;
    int v;

    std::getline(ss, token, ':');
    ss >> v;
    vals[token] = v;
  }

  while (std::getline(std::cin, line)) {
    instructions.push_back(line);        
  }

  std::cout << run(vals, instructions) << std::endl;
}
