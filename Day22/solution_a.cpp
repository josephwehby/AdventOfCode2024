#include <iostream>
#include <vector>

unsigned long long generate(unsigned long long secret) {
  unsigned long long result;

  result = secret * 64;
  secret = (secret ^ result) % 16777216;
  result = secret / 32;
  secret = (secret ^ result) % 16777216;
  result = secret * 2048;
  secret = (secret ^ result) % 16777216;
  
  return secret;
}

int main() {
  std::string line;
  unsigned long long total = 0;
  while (std::getline(std::cin, line)) {
    
    unsigned long long secret = std::stoull(line);

    for (int i = 0; i < 2000; i++) {
      secret = generate(secret);
    }

    total += secret; 
  }

  std::cout << total << std::endl;
  return 0;
}
