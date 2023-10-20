#include <iostream>
#include <string>

const int kAplhabetLenght = 26;

int CostBetweenLetters(int letter_1, int letter_2) {
  int cost_counterclockwise = letter_2 - letter_1;
  int cost_clockwise = letter_1 + kAplhabetLenght - letter_2;
  if (cost_clockwise < cost_counterclockwise) {
    return cost_clockwise;
  }
  return cost_counterclockwise;
}

int main() {
  std::string word = "";
  std::cin >> word;
  int cost = 0;
  int last_letter = 0;
  int this_letter = word[0] - 'a';
  cost += CostBetweenLetters(last_letter, this_letter);
  for (int i_letter = 1; i_letter < word.size(); i_letter += 1) {
    last_letter = word[i_letter - 1] - 'a';
    this_letter = word[i_letter] - 'a';
    if (this_letter > last_letter) {
      cost += CostBetweenLetters(last_letter, this_letter);
    }
    else {
      cost += CostBetweenLetters(this_letter, last_letter);
    }
  }
  std::cout << cost << '\n';
  return 0;
}