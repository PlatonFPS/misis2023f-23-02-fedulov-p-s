#include <iostream>
#include <vector>
#include <queue>
#include <map>

const int kAlphabetLenhgt = 26;

void InitializeGraph(std::vector<std::vector<int>>& graph) {
  for (int i_row = 0; i_row < graph.size(); i_row += 1) {
    for (int i_col = 0; i_col < graph[i_row].size(); i_col += 1) {
      graph[i_row][i_col] = -1;
    }
  }
}

void ClearBusy(std::vector<bool>& busy) {
  for (int i_row = 0; i_row < busy.size(); i_row += 1) {
    busy[i_row] = false;
  }
}

void FindShortestPath(std::map<int, int>& final_queue,
  std::vector<std::vector<int>>& graph,
  std::vector<bool>& busy,
  const int& start_letter) {
  std::priority_queue<std::pair<int, int>> temp_queue;
  temp_queue.push({ 0, start_letter });
  while (!temp_queue.empty()) {
    std::pair<int, int> letter = temp_queue.top();
    int cost = -letter.first;
    int letter_1 = letter.second;
    temp_queue.pop();
    if (busy[letter_1]) {
      continue;
    }
    busy[letter_1] = true;
    if (final_queue.find(letter_1) != final_queue.end()) {
      if (final_queue[letter_1] < cost) {
        cost = final_queue[letter_1];
      }
    }
    final_queue[letter_1] = cost;
    for (int letter_2 = 0; letter_2 < kAlphabetLenhgt; letter_2 += 1) {
      if (graph[letter_1][letter_2] != -1) {
        temp_queue.push({ -graph[letter_1][letter_2] - cost, letter_2 });
      }
    }
  }
  return;
}

int FindShortestPathBeetwenLetters(int& letter_1, int& letter_2,
  std::vector<std::vector<int>>& graph,
  std::vector<bool>& busy) {

  return -1;
}

int main() {
  std::string word_1 = "";
  std::string word_2 = "";
  std::cin >> word_1 >> word_2;
  int n_swap = 0;
  std::cin >> n_swap;
  std::vector<std::vector<int>> swaps(kAlphabetLenhgt, std::vector<int>(kAlphabetLenhgt));
  std::vector<bool> busy(kAlphabetLenhgt);
  InitializeGraph(swaps);
  ClearBusy(busy);
  for (int i_swap = 0; i_swap < n_swap; i_swap += 1) {
    char letter_a = ' ';
    char letter_b = ' ';
    int cost = 0;
    std::cin >> letter_a >> letter_b >> cost;
    if (swaps[letter_a - 'a'][letter_b - 'a'] != -1) {
      int prevcost = swaps[letter_a - 'a'][letter_b - 'a'];
      if (prevcost < cost) {
        cost = prevcost;
      }
    }
    swaps[letter_a - 'a'][letter_b - 'a'] = cost;
  }
  std::cout << "* ";
  for (char c = 'a'; c <= 'z'; c += 1) {
    std::cout << c << ' ';
  }
  std::cout << '\n';
  for (int i_letter_1 = 0; i_letter_1 < kAlphabetLenhgt; i_letter_1 += 1) {
    std::cout << static_cast<char>(i_letter_1 + 'a') << ' ';
    for (int i_letter_2 = 0; i_letter_2 < kAlphabetLenhgt; i_letter_2 += 1) {
      if (swaps[i_letter_1][i_letter_2] == -1) {
        std::cout << ". ";
      }
      else {
        std::cout << swaps[i_letter_1][i_letter_2] << ' ';
      }
    }
    std::cout << '\n';
  }
  std::cout << '\n';
  if (word_1.size() != word_2.size()) {
    std::cout << "-1\n";
    return 0;
  }
  int overall_cost = 0;
  bool impossible = false;
  for (int i_letter = 0; i_letter < word_1.size(); i_letter += 1) {
    int letter_1 = (word_1[i_letter] - 'a');
    int letter_2 = (word_2[i_letter] - 'a');
    if (letter_1 == letter_2) {
      continue;
    }
    int current_cost = FindShortestPathBeetwenLetters(letter_1, letter_2, swaps, busy);
    if (current_cost == -1) {
      impossible = true;
      break;
    }
    overall_cost += current_cost;
    word_1[i_letter] = static_cast<char>(letter_1 + 'a');
    word_2[i_letter] = static_cast<char>(letter_2 + 'a');

    std::map<int, int> shortest_path_from_1;
    FindShortestPath(shortest_path_from_1, swaps, busy, letter_1);
    ClearBusy(busy);
    std::cout << static_cast<char>(letter_1 + 'a') << '\n';
    for (std::pair<int, int> it : shortest_path_from_1) {
      std::cout << static_cast<char>(it.first + 'a') << " - " << it.second << '\n';
    }
    std::cout << "\n\n\n";
  }
  if (impossible) {
    std::cout << "-1\n";
  }
  else {
    std::cout << overall_cost << '\n' << word_1 << '\n';
  }
}