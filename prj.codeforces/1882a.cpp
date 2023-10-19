#include <iostream>
#include <string>

int main() {
  int amount_of_data_sets;
  std::cin >> amount_of_data_sets;
  for (int i_data_set = 0; i_data_set < amount_of_data_sets; i_data_set += 1) {
    int amount_of_numbers = 0;
    std::cin >> amount_of_numbers;
    int max_b = 0;
    for (int i_number = 0; i_number < amount_of_numbers; i_number += 1) {
      max_b += 1;
      int number = 0;
      std::cin >> number;
      if (max_b == number) {
        max_b += 1;
      }
    }
    std::cout << max_b << '\n';
  }
}
