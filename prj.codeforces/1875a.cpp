#include <iostream>
#include <string>

int main() {
  int amount_of_data_sets;
  std::cin >> amount_of_data_sets;
  for (int i_data_set = 0; i_data_set < amount_of_data_sets; i_data_set += 1) {
    int max_timer = 0;
    int start_timer = 0;
    int amount_of_instruments = 0;
    std::cin >> max_timer >> start_timer;
    std::cin >> amount_of_instruments;
    long long answer = start_timer;
    for (int i_instrument = 0; i_instrument < amount_of_instruments; i_instrument += 1) {
      int instrument = 0;
      std::cin >> instrument;
      if (instrument >= max_timer) {
        instrument = max_timer - 1;
      }
      answer += instrument;
    }
    std::cout << answer << '\n';
  }
}
