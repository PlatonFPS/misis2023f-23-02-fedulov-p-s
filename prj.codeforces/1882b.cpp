#include <iostream>
#include <vector>
#include <set>

int main() {
  int amount_of_data_sets;
  std::cin >> amount_of_data_sets;
  for (int i_data_set = 0; i_data_set < amount_of_data_sets; i_data_set += 1) {
    int amount_of_sequences = 0;
    std::cin >> amount_of_sequences;
    std::vector<std::vector<int>> sequences(amount_of_sequences);
    for (int i_sequence = 0; i_sequence < amount_of_sequences; i_sequence += 1) {
      int sequence_lenght = 0;
      std::cin >> sequence_lenght;
      sequences[i_sequence].resize(sequence_lenght, 0);
      for (int i_number = 0; i_number < sequence_lenght; i_number += 1) {
        int number = 0;
        std::cin >> number;
        sequences[i_sequence][i_number] = number;
      }
    }
    std::set<int> ultimate_set;
    for (int i_sequence = 0; i_sequence < amount_of_sequences; i_sequence += 1) {
      for (int i_number = 0; i_number < sequences[i_sequence].size(); i_number += 1) {
        ultimate_set.insert(sequences[i_sequence][i_number]);
      }
    }
    int answer = 0;
    for (int number : ultimate_set) {
      std::set<int> temporary_set;
      for (int i_sequence = 0; i_sequence < amount_of_sequences; i_sequence += 1) {
        bool skip_sequence = false;
        for (int i_number = 0; i_number < sequences[i_sequence].size(); i_number += 1) {
          if (sequences[i_sequence][i_number] == number) {
            skip_sequence = true;
            break;
          }
        }
        if (skip_sequence) {
          continue;
        }
        for (int i_number = 0; i_number < sequences[i_sequence].size(); i_number += 1) {
          temporary_set.insert(sequences[i_sequence][i_number]);
        }
      }
      if (answer < temporary_set.size()) {
        answer = temporary_set.size();
      }
    }
    std::cout << answer << '\n';
  }
}
