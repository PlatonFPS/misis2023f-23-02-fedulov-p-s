#include <iostream>
#include <string>

int main() {
  int amount_of_data_sets;
  std::cin >> amount_of_data_sets;
  for (int i_data_set = 0; i_data_set < amount_of_data_sets; i_data_set += 1) {
    int temp = 0;
    std::cin >> temp;
    int lenght_of_sub_str = 0;
    std::cin >> lenght_of_sub_str;
    std::string binary_str = "";
    std::cin >> binary_str;
    bool impossible = false;
    for (int i_sub_str = 0; i_sub_str < lenght_of_sub_str; i_sub_str += 1) {
      char c = '?'; //char that should be in every position = i_sub_str + a * (lenght_of_sub_str)
      for (int i_char = i_sub_str; i_char < binary_str.size(); i_char += lenght_of_sub_str) {
        if (binary_str[i_char] != '?') {
          c = binary_str[i_char];
          break;
        }
      }
      int start_char = 0; //filling indexes before the first found without '?'
      for (start_char = i_sub_str; start_char < binary_str.size(); start_char += lenght_of_sub_str) {
        if (binary_str[start_char] != '?') {
          break;
        }
        binary_str[start_char] = c;
      }
      for (start_char; start_char < binary_str.size(); start_char += lenght_of_sub_str) {
        if (binary_str[start_char] != '?' && binary_str[start_char] != c) {
          impossible = true;
          break;
        }
        else {
          binary_str[start_char] = c;
        }
      }
      if (impossible) {
        break;
      }
    }
    if (impossible) {
      std::cout << "NO\n";
      continue;
    }
    int ones_in_sub_str = 0;
    int zeros_in_sub_str = 0;
    int vacant_in_sub_str = 0;
    for (int i_char = 0; i_char < lenght_of_sub_str; i_char += 1) {
      if (binary_str[i_char] == '1') {
        ones_in_sub_str += 1;
      }
      else if (binary_str[i_char] == '0') {
        zeros_in_sub_str += 1;
      }
      else {
        vacant_in_sub_str += 1;
      }
    }
    int delta = std::abs(ones_in_sub_str - zeros_in_sub_str);
    if (delta - vacant_in_sub_str <= 0) {
      int inverse_delta = vacant_in_sub_str - delta;
      if (inverse_delta % 2 == 0) {
        std::cout << "YES\n";
        continue;
      }
    }
    std::cout << "NO\n";
  }
}
