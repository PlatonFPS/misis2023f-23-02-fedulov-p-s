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

int FindShortestPathBeetwenLetters(int& letter_1, const int& letter_2,
  std::vector<std::vector<int>>& graph) {
  //std::cout << "  " << letter_2 << '\n';
  std::vector<int> paths_1(kAlphabetLenhgt, -1);
  std::vector<int> paths_2(kAlphabetLenhgt, -1);
  std::priority_queue<std::pair<int, int>> queue_1;
  queue_1.push({ 0, letter_1 });
  std::priority_queue<std::pair<int, int>> queue_2;
  queue_2.push({ 0, letter_2 });
  int min_cost = -1;
  while (!queue_1.empty() || !queue_2.empty()) {
    int temp_letter_1 = -1;
    if (!queue_1.empty()) {
      int cost = -queue_1.top().first;
      int letter = queue_1.top().second;
      temp_letter_1 = letter;
      queue_1.pop();
      if (paths_1[letter] == -1) {
        paths_1[letter] = cost;
        for (int i_letter = 0; i_letter < kAlphabetLenhgt; i_letter += 1) {
          if (graph[letter][i_letter] != -1) {
            queue_1.push({ -graph[letter][i_letter] - cost, i_letter });
          }
        }
      }
    }
    int temp_letter_2 = -1;
    if (!queue_2.empty()) {
      int cost = -queue_2.top().first;
      int letter = queue_2.top().second;
      temp_letter_2 = letter;
      queue_2.pop();
      if (paths_2[letter] == -1) {
        paths_2[letter] = cost;
        for (int i_letter = 0; i_letter < kAlphabetLenhgt; i_letter += 1) {
          if (graph[letter][i_letter] != -1) {
            queue_2.push({ -graph[letter][i_letter] - cost, i_letter });
          }
        }
      }
    }
    if (temp_letter_1 != -1) {
      if (paths_2[temp_letter_1] != -1) {
        int cost = paths_1[temp_letter_1] + paths_2[temp_letter_1];
        if (cost < min_cost || min_cost == -1) {
          min_cost = cost;
          letter_1 = temp_letter_1;
        }
      }
    }
    if (temp_letter_2 != -1) {
      if (paths_1[temp_letter_2] != -1) {
        int cost = paths_2[temp_letter_2] + paths_1[temp_letter_2];
        if (cost < min_cost || min_cost == -1) {
          min_cost = cost;
          letter_1 = temp_letter_2;
        }
      }
    }
  }
  return min_cost;
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
  /*
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
  */
  int overall_cost = 0;
  bool impossible = false;
  for (int i_letter = 0; i_letter < word_1.size(); i_letter += 1) {
    int letter_1 = (word_1[i_letter] - 'a');
    int letter_2 = (word_2[i_letter] - 'a');
    //std::cout << word_2[i_letter] << '\n';
    //std::cout << static_cast<char>(letter_1 + 'a') << " - ";
    //std::cout << " " << letter_2 << '\n';
    int current_cost = FindShortestPathBeetwenLetters(letter_1, letter_2, swaps);
    if (current_cost == -1) {
      impossible = true;
      break;
    }
    overall_cost += current_cost;
    word_1[i_letter] = static_cast<char>(letter_1 + 'a');
    //std::cout << current_cost << " - " << static_cast<char>(letter_1 + 'a') << '\n';
  }
  if (impossible) {
    std::cout << "-1\n";
  }
  else {
    std::cout << overall_cost << '\n' << word_1 << '\n';
  }
  return 0;
}
