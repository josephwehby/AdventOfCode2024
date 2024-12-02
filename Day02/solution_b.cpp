#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>

bool checkSafe(std::vector<int>& report) {
  bool increase = false;
  if (report[1] > report[0]) increase = true;

  for (int i = 1; i < report.size(); i++) {
    if (report[i] == report[i-1]) return false;
    if (increase && report[i] < report[i-1]) return false;
    if (!increase && report[i] > report[i-1]) return false;
    if (abs(report[i] - report[i-1]) > 3) return false;
  }

  return true;
}

int main() {
  
  std::string line;
  int safe = 0;
  while (getline(std::cin, line)) {
    std::stringstream ss;
    ss << line;
    
    int val;
    std::vector<int> report;
    while (ss >> val) report.push_back(val);

    bool isSafe = checkSafe(report);
    if (isSafe) {
      safe++;
    } else {
      for (int i = 0; i < report.size(); i++) {
        auto copy = report;
        copy.erase(copy.begin()+i);
        bool ans = checkSafe(copy);
        if (ans) {
          safe++;
          break;
        }
      }
    }
  }

  std::cout << safe << std::endl;
}
