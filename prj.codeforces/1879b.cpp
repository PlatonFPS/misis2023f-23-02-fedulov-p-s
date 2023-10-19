#include <iostream>
#include <vector>

int main() {
  int n_data_set = 0;
  std::cin >> n_data_set;
  for (int i_data_set = 0; i_data_set < n_data_set; i_data_set += 1) {
    int matrix_size = 0;
    std::cin >> matrix_size;
    std::vector<long long> cols(matrix_size, 0);
    std::vector<long long> rows(matrix_size, 0);
    long long min_row = 1e11;
    long long row_cost = 0;
    for (int i_row = 0; i_row < matrix_size; i_row += 1) {
      std::cin >> rows[i_row];
      if (rows[i_row] < min_row) {
        min_row = rows[i_row];
      }
      row_cost += rows[i_row];
    }
    long long min_col = 1e11;
    long long col_cost = 0;
    for (int i_col = 0; i_col < matrix_size; i_col += 1) {
      std::cin >> cols[i_col];
      if (cols[i_col] < min_col) {
        min_col = cols[i_col];
      }
      col_cost += cols[i_col];
    }
    row_cost += min_col * matrix_size;
    col_cost += min_row * matrix_size;
    if (row_cost < col_cost) {
      std::cout << row_cost << '\n';
    }
    else {
      std::cout << col_cost << '\n';
    }
  }
  return 0;
}