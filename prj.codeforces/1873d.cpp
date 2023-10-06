#include <iostream>

int main() {
  int n_data_set = 0;
  std::cin >> n_data_set;
  for (int i_data_set = 0; i_data_set < n_data_set; i_data_set += 1) {
    int paper_lenght = 0;
    int seq_lenght = 0;
    std::cin >> paper_lenght >> seq_lenght;
    int erase_start = -1;
    int erase_end = -1;
    int erase_count = 0;
    for (int i_cell = 0; i_cell < paper_lenght; i_cell += 1) {
      char cell;
      std::cin >> cell;
      if (cell == 'B') {
        if (i_cell < erase_start || i_cell > erase_end) {
          erase_start = i_cell;
          erase_end = erase_start + seq_lenght - 1;
          erase_count += 1;
        }
      }
    }
    std::cout << erase_count << '\n';
  }
}
