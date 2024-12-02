#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>

int main() {
  
  std::string line;
  int safe = 0;
  while (getline(std::cin, line)) {
    std::stringstream ss;
    ss << line;
    
    int val;
    std::vector<int> report;
    while (ss >> val) report.push_back(val);
    bool increase = false;
    if (report[1] > report[0]) increase = true;

    int count = 0;
    for (int i = 1; i < report.size(); i++) {
      if (report[i] == report[i-1]) break;
      if (increase && report[i] < report[i-1]) break;
      if (!increase && report[i] > report[i-1]) break;
      if (abs(report[i] - report[i-1]) > 3) break;
      count++;
    }

    if (count == report.size()-1) safe++;
  }

  std::cout << safe << std::endl;
}
