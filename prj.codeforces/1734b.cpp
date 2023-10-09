#include <iostream>

int main() {
  int n_data_set = 0;
  std::cin >> n_data_set;
  for (int i_data_set = 0; i_data_set < n_data_set; i_data_set += 1) {
    int n_floor;
    std::cin >> n_floor;
    for (int i_floor = 1; i_floor <= n_floor; i_floor += 1) {
      for (int i_room = 1; i_room <= i_floor; i_room += 1) {
        if (i_room == 1 || i_room == i_floor) {
          std::cout << "1 ";
        }
        else {
          std::cout << "0 ";
        }
      }
      std::cout << '\n';
    }
  }
  return 0;
}