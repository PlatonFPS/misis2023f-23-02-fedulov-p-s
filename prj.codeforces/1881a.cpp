#include <iostream>
#include <string>

int main() {
  const int kMaxNumberOfSteps = 5;
  int n_data_set = 0;
  std::cin >> n_data_set;
  for (int i_data_set = 0; i_data_set < n_data_set; i_data_set += 1) {
    int len_str_1 = 0;
    int len_str_2 = 0;
    std::cin >> len_str_1 >> len_str_2;
    std::string str_1 = "";
    std::string str_2 = "";
    std::cin >> str_1 >> str_2;
    bool impossible = true;
    for (int i_step = 0; i_step <= kMaxNumberOfSteps; i_step += 1) {
      if (str_1.find(str_2) != std::string::npos) {
        std::cout << i_step << '\n';
        impossible = false;
        break;
      }
      str_1 += str_1;
    }
    if (impossible) {
      std::cout << "-1\n";
    }
  }
}