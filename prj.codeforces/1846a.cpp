#include <iostream>

int main() {
  int n_data_set = 0;
  std::cin >> n_data_set;
  for (int i_data_set = 0; i_data_set < n_data_set; i_data_set += 1) {
    int n_nail = 0;
    std::cin >> n_nail;
    int n_cut = 0;
    for (int i_nail = 0; i_nail < n_nail; i_nail += 1) {
      int height = 0;
      int lenght = 0;
      std::cin >> height >> lenght;
      if (height > lenght) {
        n_cut += 1;
      }
    }
    std::cout << n_cut << '\n';
  }
}