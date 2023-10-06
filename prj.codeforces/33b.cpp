#include <iostream>
#include <vector>
#include <map>

int main() {
  std::string word_1 = "";
  std::string word_2 = "";
  std::cin >> word_1 >> word_2;
  int n_swap = 0;
  std::cin >> n_swap;
  std::map<std::pair<char, char>, int> swaps = {};
  for (int i_swap = 0; i_swap < n_swap; i_swap += 1) {
    char letter_a = ' ';
    char letter_b = ' ';
    int cost = 0;
    std::cin >> letter_a >> letter_b >> cost;
    swaps[{letter_a, letter_b}] = cost;
  }
  std::vector<std::vector<int>> dp(word_1.size(), std::vector<int>(word_2.size()));
  for (int i_row = 0; i_row < word_1.size(); i_row += 1) {

  }
}