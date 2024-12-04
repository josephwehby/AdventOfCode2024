#include <iostream>
#include <vector>

bool validMove(std::vector<std::string>& word_search, int row, int col) {
  if (row >= word_search.size() || row < 0 || col >= word_search[0].size() || col < 0) return false;
  return true;
}

int findXMAS(std::vector<std::string>& word_search, int row, int col) {
  int count = 0;
  std::string answer = "XMAS";
  int r, c;
  std::string s;
  int directions[8][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {-1,1}, {1,-1}, {-1,-1}};
  
  for (int i = 0; i < 8; i++) {
    
    int dx = directions[i][0];
    int dy = directions[i][1];
    
    r = row;
    c = col;
    s = "";
    for (int j = 0; j < 4; j++) {
      if (!validMove(word_search, r, c)) break;
      s += word_search[r][c];
      r += dy;
      c += dx;
    }

    if (s == answer) count++;
  }

  return count;
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
      if (word_search[row][col] == 'X') total += findXMAS(word_search, row, col);
    }
  }

  std::cout << total << std::endl;

  return 0;
}
