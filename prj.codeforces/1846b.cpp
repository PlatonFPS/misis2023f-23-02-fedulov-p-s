#include <iostream>
#include <vector>

const int kMatrixSize = 3;

int main() {
  int n_data_set = 0;
  std::cin >> n_data_set;
  for (int i_data_set = 0; i_data_set < n_data_set; i_data_set += 1) {
    std::vector<std::vector<char>> matrix(kMatrixSize, std::vector<char>(kMatrixSize));
    for (int i_row = 0; i_row < kMatrixSize; i_row += 1) {
      for (int i_col = 0; i_col < kMatrixSize; i_col += 1) {
        std::cin >> matrix[i_row][i_col];
      }
    }
    //horizontal
    if (matrix[0][0] == matrix[0][1] && matrix[0][0] == matrix[0][2] && matrix[0][0] != '.') {
      std::cout << matrix[0][0] << '\n';
      continue;
    }
    if (matrix[1][0] == matrix[1][1] && matrix[1][0] == matrix[1][2] && matrix[1][0] != '.') {
      std::cout << matrix[1][0] << '\n';
      continue;
    }
    if (matrix[2][0] == matrix[2][1] && matrix[2][0] == matrix[2][2] && matrix[2][0] != '.') {
      std::cout << matrix[2][0] << '\n';
      continue;
    }
    //vertical
    if (matrix[0][0] == matrix[1][0] && matrix[0][0] == matrix[2][0] && matrix[0][0] != '.') {
      std::cout << matrix[0][0] << '\n';
      continue;
    }
    if (matrix[0][1] == matrix[1][1] && matrix[0][1] == matrix[2][1] && matrix[0][1] != '.') {
      std::cout << matrix[0][1] << '\n';
      continue;
    }
    if (matrix[0][2] == matrix[1][2] && matrix[0][2] == matrix[2][2] && matrix[0][2] != '.') {
      std::cout << matrix[0][2] << '\n';
      continue;
    }
    //diagonal
    if (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2] && matrix[0][0] != '.') {
      std::cout << matrix[0][0] << '\n';
      continue;
    }
    if (matrix[2][0] == matrix[1][1] && matrix[2][0] == matrix[0][2] && matrix[2][0] != '.') {
      std::cout << matrix[2][0] << '\n';
      continue;
    }
    std::cout << "DRAW\n";
  }
  return 0;
}