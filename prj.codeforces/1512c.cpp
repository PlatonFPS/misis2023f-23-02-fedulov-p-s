#include <iostream>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int data_sets = 0;
  std::cin >> data_sets;
  for (int i_data_set = 0; i_data_set < data_sets; i_data_set += 1) {
    int amount_of_0 = 0, amount_of_1 = 0;
    std::cin >> amount_of_0 >> amount_of_1;
    std::string s = "";
    std::cin >> s;
    int left_to_fill_0 = amount_of_0;
    int left_to_fill_1 = amount_of_1;
    if (amount_of_0 % 2 == 1 &&
      amount_of_1 % 2 == 1) {
      std::cout << "-1\n";
      continue;
    }
    if ((amount_of_0 + amount_of_1) % 2 == 1) {
      int i_middle = (amount_of_0 + amount_of_1) / 2;
      if (s[i_middle] == '?') {
        if (amount_of_0 % 2 == 1) {
          left_to_fill_0 -= 1;
          s[i_middle] = '0';
        }
        else {
          left_to_fill_1 -= 1;
          s[i_middle] = '1';
        }
      }
      else {
        if (s[i_middle] == '0' && amount_of_0 % 2 == 1) {
          left_to_fill_0 -= 1;
        }
        else if (s[i_middle] == '1' && amount_of_1 % 2 == 1) {
          left_to_fill_1 -= 1;
        }
        else {
          std::cout << "-1\n";
          continue;
        }
      }
    }
    bool impossible = 0;
    for (int i_letter = 0; i_letter < s.size() / 2; i_letter += 1) {
      if (s[i_letter] == '?') {
        if (s[(s.size() - 1) - i_letter] == '?') {
          continue;
        }
        s[i_letter] = s[(s.size() - 1) - i_letter];
      }
      else {
        if (s[(s.size() - 1) - i_letter] != '?' &&
          s[(s.size() - 1) - i_letter] != s[i_letter]) {
          std::cout << "-1\n";
          impossible = 1;
          break;
        }
        s[(s.size() - 1) - i_letter] = s[i_letter];
      }
      if (s[i_letter] == '0') {
        left_to_fill_0 -= 2;
      }
      else {
        left_to_fill_1 -= 2;
      }
    }
    if (impossible) {
      continue;
    }
    for (int i_letter = 0; i_letter < s.size() / 2; i_letter += 1) {
      if (s[i_letter] == '?') {
        if (left_to_fill_0 > 0) {
          s[i_letter] = '0';
          s[(s.size() - 1) - i_letter] = '0';
          left_to_fill_0 -= 2;
        }
        else {
          s[i_letter] = '1';
          s[(s.size() - 1) - i_letter] = '1';
          left_to_fill_1 -= 2;
        }
      }
    }
    if (left_to_fill_0 > 0 || left_to_fill_1 > 0) {
      std::cout << "-1\n";
      continue;
    }
    std::cout << s << '\n';
  }
}
