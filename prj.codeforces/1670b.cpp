#include <iostream>
#include <string>
#include <vector>

bool IsSpecialLetter(const char& letter, std::vector<char>& special_letters) {
  for (char s_letter : special_letters) {
    if (letter == s_letter) return 1;
  }
  return 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int data_sets = 0;
  std::cin >> data_sets;
  for (int i_data_set = 0; i_data_set < data_sets; i_data_set += 1) {
    int temp = 0;
    std::cin >> temp;
    std::string password;
    std::cin >> password;
    int k = 0;
    std::cin >> k;
    std::vector<char> special_letters(k);
    for (int i_letter = 0; i_letter < k; i_letter += 1) {
      std::cin >> special_letters[i_letter];
    }
    int i_first_s_letter = -1;
    for (int i_letter = password.size() - 1; i_letter >= 0; i_letter -= 1) {
      if (IsSpecialLetter(password[i_letter], special_letters)) {
        i_first_s_letter = i_letter;
        break;
      }
    }
    if (i_first_s_letter == 0) {
      std::cout << "0\n";
      continue;
    }
    int current_step = 0;
    int max_step = 0;
    for (int i_letter = i_first_s_letter; i_letter >= 0; i_letter -= 1) {
      current_step += 1;
      if (IsSpecialLetter(password[i_letter], special_letters)) {
        if (current_step > max_step) {
          max_step = current_step;
        }
        current_step = 0;
      }
    }
    if (current_step > max_step) {
      max_step = current_step;
    }
    std::cout << max_step << '\n';
  }
}
