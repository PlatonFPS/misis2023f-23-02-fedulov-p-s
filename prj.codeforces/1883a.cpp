#include <iostream>

const int kNumCount = 4;

int main() {
  int n_data_set = 0;
  std::cin >> n_data_set;
  for (int i_data_set = 0; i_data_set < n_data_set; i_data_set += 1) {
    int last_num = 0;
    int n_second = 0;
    for (int i_num = 0; i_num < kNumCount; i_num += 1) {
      char digit = '.';
      std::cin >> digit;
      int this_num = digit - '0';
      this_num = (this_num + 9) % 10;
      n_second += std::abs(this_num - last_num) + 1;
      last_num = this_num;
    }
    std::cout << n_second << '\n';
  }
}