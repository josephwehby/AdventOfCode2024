#include <iostream>
#include <vector>

int findXMAS(std::vector<std::string>& word_search, int row, int col) {
  if (col >= word_search[0].size()-1 || col < 1 || row >= word_search.size()-1 || row < 1) return 0;
  
  std::string d1 = std::string(1, word_search[row-1][col-1]) + word_search[row+1][col+1];
  std::string d2 = std::string(1, word_search[row+1][col-1]) + word_search[row-1][col+1];
  

  if ((d1 == "MS" || d1 == "SM") && (d2 == "MS" || d2 == "SM")) return 1;

  return 0;
}

int main() {
  int total = 0;
  std::vector<std::string> word_search;
   
  std::string line;
  
  while (getline(std::cin, line)) {
    word_search.push_back(line);
  }

  for (int row = 0; row < word_search.size(); row++) {
    for (int col = 0; col < word_search[row].size(); col++) {
      if (word_search[row][col] == 'A') total += findXMAS(word_search, row, col);
    }
  }

  std::cout << total << std::endl;

  return 0;
}
