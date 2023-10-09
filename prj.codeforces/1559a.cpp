#include <iostream>

int main() {
  int n_data_set = 0;
  std::cin >> n_data_set;
  for (int i_data_set = 0; i_data_set < n_data_set; i_data_set += 1) {
    int n_number = 0;
    std::cin >> n_number;
    int answer = 0;
    std::cin >> answer;
    for (int i_number = 1; i_number < n_number; i_number += 1) {
      int number = 0;
      std::cin >> number;
      answer = number & answer;
    }
    std::cout << answer << '\n';
  }
  return 0;
}