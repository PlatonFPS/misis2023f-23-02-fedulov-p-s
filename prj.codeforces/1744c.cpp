#include <iostream>
#include <string>

int main() {
  int n_data_set = 0;
  std::cin >> n_data_set;
  for (int i_data_set = 0; i_data_set < n_data_set; i_data_set += 1) {
    int line_lenght = 0;
    char start_color = '.';
    std::cin >> line_lenght >> start_color;
    std::string line = "";
    std::cin >> line;
    int i_first_green = -1;
    int i_last_color = -1;
    int min_time_required = 0;
    for (int i_char = 0; i_char < line.size(); i_char += 1) {
      if (line[i_char] == 'g' && i_first_green == -1) {
        i_first_green = i_char;
      }
      if (line[i_char] == start_color) {
        if (i_last_color == -1) {
          i_last_color = i_char;
        }
      }
      if (line[i_char] == 'g') {
        if (i_last_color != -1) {
          int time_required = i_char - i_last_color;
          if (time_required > min_time_required) {
            min_time_required = time_required;
          }
        }
        i_last_color = -1;
      }
    }
    if (i_last_color != -1)
    {
      int time_required = i_first_green + line.size() - i_last_color;
      if (time_required > min_time_required) {
        min_time_required = time_required;
      }
    }
    std::cout << min_time_required << '\n';
  }
  return 0;
}