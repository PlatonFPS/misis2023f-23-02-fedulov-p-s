#include <iostream>
#include <vector>

int main() {
  const int kTotalPlaces = 100;
  int amount_of_data_sets;
  std::cin >> amount_of_data_sets;
  for (int i_data_set = 0; i_data_set < amount_of_data_sets; i_data_set += 1) {
    int amount_of_rounds, amount_of_extra_rounds;
    std::cin >> amount_of_rounds >> amount_of_extra_rounds;
    std::vector<bool> places_present(kTotalPlaces, 0);
    for (int i_round = 0; i_round < amount_of_rounds; i_round += 1) {
      int place;
      std::cin >> place;
      places_present[place - 1] = true;
    }
    int amount_of_extra_rounds_needed = 0;
    int answer = 0;
    for (int i_place = 0; i_place < kTotalPlaces; i_place += 1) {
      if (!places_present[i_place]) {
        amount_of_extra_rounds_needed += 1;
        if (amount_of_extra_rounds_needed > amount_of_extra_rounds) {
          break;
        }
      }
      answer += 1;
    }
    if (amount_of_extra_rounds_needed < amount_of_extra_rounds) {
      answer += amount_of_extra_rounds - amount_of_extra_rounds_needed;
    }
    std::cout << answer << '\n';
  }
}