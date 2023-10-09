#include <iostream>
#include <vector>

int main() {
  int n_data_set = 0;
  std::cin >> n_data_set;
  for (int i_data_set = 0; i_data_set < n_data_set; i_data_set += 1) {
    int matrix_size = 0;
    std::cin >> matrix_size;
    std::vector<int> rows(matrix_size, 0);
    std::vector<int> cols(matrix_size, 0);
    for (int i_row = 0; i_row < matrix_size; i_row += 1) {
      std::cin >> rows[i_row];
    }
    for (int i_col = 0; i_col < matrix_size; i_col += 1) {
      std::cin >> cols[i_col];
    }

  }
  return 0;
}