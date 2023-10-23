#include <iostream>

int main() {
  int weight;
  std::cin >> weight;
  if (weight > 2 && weight % 2 == 0) {
    std::cout << "YES\n";
  }
  else{
    std::cout << "NO\n";
  }
}