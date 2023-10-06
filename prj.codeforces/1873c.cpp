#include <iostream>
#include <vector>
#include <set>

int main() {
  const int kNumberOfRow = 10;
  const int kNumberOfColumn = 10;
  int n_data_set = 0;
  std::cin >> n_data_set;
  for (int i_data_set = 0; i_data_set < n_data_set; i_data_set += 1) {
    int score = 0;
    for (int i_row = 1; i_row <= kNumberOfRow; i_row += 1) {
      for (int i_column = 1; i_column <= kNumberOfColumn; i_column += 1) {
        char cell;
        std::cin >> cell;
        if (cell == 'X') {
          int min_row = std::min(i_row, kNumberOfRow - i_row + 1);
          int min_column = std::min(i_column, kNumberOfColumn - i_column + 1);
          score += std::min(min_row, min_column);
        }
      }
    }
    std::cout << score << '\n';
  }
}
