#include <iostream>
#include <vector>

void FillDiagonal(const int& diagonal_x, const int& diagonal_y,
  std::vector<std::vector<bool>>& matrix,
  int matrix_size) {
  int up_x = diagonal_x, up_y = diagonal_y;
  while (up_x < matrix_size && up_y >= 0) {
    if (!(up_x < 0) && !(up_y >= matrix_size)) {
      matrix[up_y][up_x] = 1;
    }
    up_x += 1;
    up_y -= 1;
  }
  int down_x = diagonal_x, down_y = diagonal_y;
  while (down_y < matrix_size && down_x >= 0) {
    if (!(down_y < 0) && !(down_x >= matrix_size)) {
      matrix[down_y][down_x] = 1;
    }
    down_y += 1;
    down_x -= 1;
  }
  return;
}

int main() {
  int data_sets;
  std::cin >> data_sets;
  for (int i_data_set = 0; i_data_set < data_sets; i_data_set += 1) {
    int matrix_size, k, x_x, x_y;
    std::cin >> matrix_size >> k >> x_x >> x_y;
    x_y -= 1;
    x_x -= 1;
    std::vector<std::vector<bool>> matrix(matrix_size,
      std::vector<bool>(matrix_size));
    for (int i_y_matrix = 0; i_y_matrix < matrix_size; i_y_matrix += 1) {
      for (int i_x_matrix = 0; i_x_matrix < matrix_size; i_x_matrix += 1) {
        matrix[i_y_matrix][i_x_matrix] = 0;
      }
    }
    int start_x = x_x;
    int start_y = -x_x + (x_y + x_x) % k;
    for (start_y; start_y < 2 * matrix_size - x_x; start_y += k)
    {
      FillDiagonal(start_x, start_y, matrix, matrix_size);
    }
    for (int i_y_matrix = 0; i_y_matrix < matrix_size; i_y_matrix += 1) {
      for (int i_x_matrix = 0; i_x_matrix < matrix_size; i_x_matrix += 1) {
        std::cout << (matrix[i_y_matrix][i_x_matrix] ? 'X' : '.');
      }
      std::cout << '\n';
    }
  }
}
