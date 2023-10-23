#include <iostream>
#include <string>

int main(){
  int n_data_set = 0;
  std::cin >> n_data_set;
  for (int i_data_set = 0; i_data_set < n_data_set; i_data_set += 1) {
    bool answer = true;
    int row_lenght = 0;
    std::cin >> row_lenght;
    std::string row;
    std::cin >> row;
    int red = 0;
    int blue = 0;
    for (int i_char = 0; i_char < row.size(); i_char++)
    {
      if (row[i_char] == 'R')red++;
      if (row[i_char] == 'B')blue++;
      if (row[i_char] == 'W' && i_char > 0 && row[i_char - 1] != 'W')
      {
        if (red + blue <= 1 || red == 0 || blue == 0)
        {
          answer = false;
          break;
        }
        red = 0;
        blue = 0;
      }
    }
    if ((row[row.size() - 1] != 'W') && (red + blue <= 1 || red == 0 || blue == 0))
    {
      if (red + blue <= 1 || red == 0 || blue == 0)
      {
        answer = false;
      }
    }
    std::cout << (answer ? "YES\n" : "NO\n");
  }
  return 0;
}