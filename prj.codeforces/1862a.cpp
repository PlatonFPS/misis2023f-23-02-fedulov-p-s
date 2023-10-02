#include <iostream>
#include <vector>

int main() {
  int number_of_data_sets;
  std::cin >> number_of_data_sets;
  for (int i = 0; i < number_of_data_sets; i += 1) {
    int strokes, collums;
    std::cin >> strokes >> collums;
    std::vector<std::vector<bool>> letters(collums, std::vector<bool>(4, false));
    for (int j = 0; j < strokes; j += 1) {
      for (int f = 0; f < collums; f += 1) {
        char c;
        std::cin >> c;
        if (c == 'v') {
          letters[f][0] = true;
        }
        if (c == 'i') {
          letters[f][1] = true;
        }
        if (c == 'k') {
          letters[f][2] = true;
        }
        if (c == 'a') {
          letters[f][3] = true;
        }
      }
    }
    int proggression = 0;
    for (int j = 0; j < collums; j += 1) {
      if (letters[j][proggression] == true) {
        proggression += 1;
      }
    }
    if (proggression >= 4) {
      std::cout << "YES\n";
    }
    else {
      std::cout << "NO\n";
    }
  }
}