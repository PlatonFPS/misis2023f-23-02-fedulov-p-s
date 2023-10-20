#include <iostream>

int main() {
  int n_data_set = 0;
  std::cin >> n_data_set;
  for (int i_data_set = 0; i_data_set < n_data_set; i_data_set += 1) {
    int n_location = 0;
    std::cin >> n_location;
    int first_water = -1;
    int last_water = -1;
    for (int i_location = 0; i_location < n_location; i_location += 1) {
      bool ground = false;
      std::cin >> ground;
      if (!ground) {
        if (first_water == -1) {
          first_water = i_location;
        }
        last_water = i_location;
      }
    }
    if (last_water + first_water == -2) {
      std::cout << "0\n";
    }
    else {
      std::cout << last_water - first_water + 2 << '\n';
    }
  }
  return 0;
}