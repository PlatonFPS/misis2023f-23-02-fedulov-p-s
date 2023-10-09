#include <iostream>
#include <vector>
#include <queue>

const int kAlphabetLenhgt = 26;

void InitializeGraph(std::vector<std::vector<int>>& graph) {
  for (int i_row = 0; i_row < graph.size(); i_row += 1) {
    for (int i_col = 0; i_col < graph[i_row].size(); i_col += 1) {
      graph[i_row][i_col] = -1;
    }
  }
}

void FindShortestPath(std::vector<int>& paths,
                      std::vector<std::vector<int>>& graph,
                      const int& start_letter) {
  std::priority_queue<std::pair<int, int>> queue;
  queue.push({ 0, start_letter });
  while (!queue.empty()) {
    int cost = -queue.top().first;
    int letter = queue.top().second;
    queue.pop();
    if (paths[letter] != -1) {
      continue;
    }
    paths[letter] = cost;
    for (int i_letter = 0; i_letter < kAlphabetLenhgt; i_letter += 1) {
      if (graph[letter][i_letter] != -1) {
        queue.push({ -(graph[letter][i_letter] + cost), i_letter });
      }
    }
  }
  return;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::string word_1 = "";
  std::string word_2 = "";
  std::cin >> word_1 >> word_2;
  int n_swap = 0;
  std::cin >> n_swap;
  std::vector<std::vector<int>> swaps(kAlphabetLenhgt, std::vector<int>(kAlphabetLenhgt));
  InitializeGraph(swaps);
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
  if (word_1.size() != word_2.size()) {
    std::cout << "-1\n";
    return 0;
  }
  int overall_cost = 0;
  for (int i_char = 0; i_char < word_1.size(); i_char += 1) {
    int letter_1 = (word_1[i_char] - 'a');
    int letter_2 = (word_2[i_char] - 'a');
    std::vector<int> paths_1(kAlphabetLenhgt, -1);
    FindShortestPath(paths_1, swaps, letter_1);
    std::vector<int> paths_2(kAlphabetLenhgt, -1);
    FindShortestPath(paths_2, swaps, letter_2);
    int min_cost = -1;
    bool possible = false;
    for (int i_letter = 0; i_letter < kAlphabetLenhgt; i_letter += 1) {
      if (paths_1[i_letter] != -1 && paths_2[i_letter] != -1) {
        int temp_cost = paths_1[i_letter] + paths_2[i_letter];
        if (temp_cost < min_cost || min_cost == -1) {
          min_cost = temp_cost;
          possible = true;
          word_1[i_char] = static_cast<char>(i_letter + 'a');
        }
      }
    }
    if (!possible) {
      std::cout << "-1\n";
      return 0;
    }
    overall_cost += min_cost;
  }
  std::cout << overall_cost << '\n' << word_1 << '\n';
  return 0;
}
