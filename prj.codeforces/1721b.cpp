#include <iostream>

int main() {
  int data_sets;
  std::cin >> data_sets;
  for (int i_data_set = 0; i_data_set < data_sets; i_data_set += 1) {
    int lines, collums, lazer_x, lazer_y, lazer_distance;
    std::cin >> lines >> collums;
    std::cin >> lazer_x >> lazer_y >> lazer_distance;
    if (collums - lazer_y <= lazer_distance) {
      if (lines - lazer_x <= lazer_distance) {
        std::cout << "-1\n";
        continue;
      }
    }
    if (lazer_y - 1 <= lazer_distance) {
      if (lazer_x - 1 <= lazer_distance) {
        std::cout << "-1\n";
        continue;
      }
    }
    if (lazer_y - 1 <= lazer_distance) {
      if (collums - lazer_y <= lazer_distance) {
        std::cout << "-1\n";
        continue;
      }
    }
    if (lazer_x - 1 <= lazer_distance) {
      if (lines - lazer_x <= lazer_distance) {
        std::cout << "-1\n";
        continue;
      }
    }
    std::cout << lines - 1 + collums - 1 << '\n';
  }
}
