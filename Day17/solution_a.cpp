#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

long long getCombo(std::vector<long long>& registers, int operand) {
  if (operand <= 3) return (long long) operand;

  return (long long)registers[operand-4];
}

void run(std::vector<int>& opcodes, std::vector<long long>& registers) {
  for (int i = 0; i < opcodes.size(); i+=2) {
    int answer;
    long long combo;
    int opcode = opcodes[i];
    int operand = opcodes[i+1];

    switch (opcode) {
      case 0:
        answer = static_cast<int>(registers[0] / pow(2, getCombo(registers, operand)));
        registers[0] = answer;
        break;
      case 1:
        registers[1] = registers[1] ^ operand;
        break;
      case 2:
        registers[1] = getCombo(registers, operand) % 8;
        break;
      case 3:
        if (registers[0] == 0) break;
        i = operand - 2;
        break;
      case 4:
        registers[1] ^= registers[2];
        break;
      case 5:
        combo = getCombo(registers, operand);
        std::cout << combo%8 << ",";
        break;
      case 6:
        answer = static_cast<int>(registers[0] / pow(2, getCombo(registers, operand)));
        registers[1] = answer;
        break;
      case 7:
        answer = static_cast<int>(registers[0] / pow(2, getCombo(registers, operand)));
        registers[2] = answer;
        break;
    }
  }
  std::cout << std::endl;
}

int main() {
  std::string line;
  std::vector<long long> registers(3, 0);
  std::vector<int> opcodes;

  while (std::getline(std::cin, line)) {
    std::stringstream ss;
    long long val;
    ss << line;

    std::string word;
    ss >> word;

    if (word == "Register") {
      ss >> word;
      ss >> val;
      registers[(int)(word[0] - 'A')] = val;
    } else if (word == "Program:") {
      std::string opcode;
      while (std::getline(ss, opcode, ',')) {
        opcodes.push_back(std::stoi(opcode));
      }
    }
  }
  run(opcodes, registers);
}
