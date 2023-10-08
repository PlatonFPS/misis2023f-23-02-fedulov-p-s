#include <iostream>

int main() {
  int n_data_set = 0;
  std::cin >> n_data_set;
  for (int i_data_set = 0; i_data_set < n_data_set; i_data_set += 1) {
    int n_num = 0;
    int k_number = 0;
    std::cin >> n_num >> k_number;
    bool possible = false;
    for (int i_number = 0; i_number < n_num; i_number += 1) {
      int number = 0;
      std::cin >> number;
      if (number == k_number) {
        possible = true;
      }
    }
    std::cout << (possible ? "YES\n" : "NO\n");
  }
  return 0;
}