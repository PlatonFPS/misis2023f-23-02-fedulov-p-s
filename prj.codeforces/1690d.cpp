#include <iostream>
#include <string>

int main() {
  int n_data_set = 0;
  std::cin >> n_data_set;
  for (int i_data_set = 0; i_data_set < n_data_set; i_data_set += 1) {
    int line_lenght = 0;
    std::cin >> line_lenght;
    int black_lenght = 0;
    std::cin >> black_lenght;
    int min_paint_count = line_lenght;
    int cur_paint_count = 0;
    std::string line = "";
    std::cin >> line;
    for (int i_cell = 0; i_cell < black_lenght; i_cell += 1) {
      if (line[i_cell] == 'W') {
        cur_paint_count += 1;
      }
    }
    if (cur_paint_count < min_paint_count) {
      min_paint_count = cur_paint_count;
    }
    int i_left = 0;
    int i_right = black_lenght;
    while (i_right < line_lenght) {
      if (line[i_left] == 'W') {
        cur_paint_count -= 1;
      }
      if (line[i_right] == 'W') {
        cur_paint_count += 1;
      }
      if (cur_paint_count < min_paint_count) {
        min_paint_count = cur_paint_count;
      }
      i_left += 1;
      i_right += 1;
    }
    std::cout << min_paint_count << '\n';
  }
}