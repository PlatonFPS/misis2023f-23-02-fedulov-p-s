#include <iostream>
#include <vector>

int main() {
  int n_data_set = 0;
  std::cin >> n_data_set;
  for (int i_data_set = 0; i_data_set < n_data_set; i_data_set += 1) {
    int matrix_lenght = 0;
    std::cin >> matrix_lenght;
    int star_1_row = -1;
    int star_1_col = -1;
    int star_2_row = -1;
    int star_2_col = -1;
    for (int i_row = 0; i_row < matrix_lenght; i_row += 1) {
      for (int i_col = 0; i_col < matrix_lenght; i_col += 1) {
        char cell = '.';
        std::cin >> cell;
        if (cell == '*') {
          if (star_1_row == -1) {
            star_1_row = i_row;
            star_1_col = i_col;
          }
          else {
            star_2_row = i_row;
            star_2_col = i_col;
          }
        }
      }
    }
    int star_3_row = -1;
    int star_3_col = -1;
    int star_4_row = -1;
    int star_4_col = -1;
    if (star_1_row == star_2_row) {
      if (star_1_row > 0) {
        star_3_row = 0;
        star_4_row = 0;
      }
      else {
        star_3_row = 1;
        star_4_row = 1;
      }
      star_3_col = star_1_col;
      star_4_col = star_2_col;
    }
    else if (star_1_col == star_2_col) {
      if (star_1_col > 0) {
        star_3_col = 0;
        star_4_col = 0;
      }
      else {
        star_3_col = 1;
        star_4_col = 1;
      }
      star_3_row = star_1_row;
      star_4_row = star_2_row;
    }
    else {
      star_3_row = star_1_row;
      star_3_col = star_2_col;
      star_4_row = star_2_row;
      star_4_col = star_1_col;
    }
    for (int i_row = 0; i_row < matrix_lenght; i_row += 1) {
      for (int i_col = 0; i_col < matrix_lenght; i_col += 1) {
        if ((i_row == star_1_row && i_col == star_1_col) ||
            (i_row == star_2_row && i_col == star_2_col) || 
            (i_row == star_3_row && i_col == star_3_col) || 
            (i_row == star_4_row && i_col == star_4_col)) {
          std::cout << '*';
        }
        else {
          std::cout << '.';
        }
      }
      std::cout << '\n';
    }
  }
  return 0;
}