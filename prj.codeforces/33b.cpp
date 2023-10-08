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

int FindShortestPathBeetwenLetters(int& letter_1, const int& letter_2,
  std::vector<std::vector<int>>& graph) {
  std::vector<int> paths_1(kAlphabetLenhgt, -1);
  std::vector<int> paths_2(kAlphabetLenhgt, -1);
  std::priority_queue<std::pair<int, int>> queue_1;
  queue_1.push({ 0, letter_1 });
  std::priority_queue<std::pair<int, int>> queue_2;
  queue_2.push({ 0, letter_2 });
  while (!queue_1.empty() || !queue_2.empty()) {
    int temp_letter_1 = -1;
    if (!queue_1.empty()) {
      int cost = -queue_1.top().first;
      int letter = queue_1.top().second;
      temp_letter_1 = letter;
      queue_1.pop();
      if (paths_1[letter] != -1) {
        continue;
      }
      paths_1[letter] = cost;
      for (int i_letter = 0; i_letter < kAlphabetLenhgt; i_letter += 1) {
        if (graph[letter][i_letter] != -1) {
          queue_1.push({ -graph[letter][i_letter] - cost, i_letter });
        }
      }
    }
    int temp_letter_2 = -1;
    if (!queue_2.empty()) {
      int cost = -queue_2.top().first;
      int letter = queue_2.top().second;
      temp_letter_2 = letter;
      queue_2.pop();
      if (paths_2[letter] != -1) {
        continue;
      }
      paths_2[letter] = cost;
      for (int i_letter = 0; i_letter < kAlphabetLenhgt; i_letter += 1) {
        if (graph[letter][i_letter] != -1) {
          queue_2.push({ -graph[letter][i_letter] - cost, i_letter });
        }
      }
    }
    int min_cost = -1;
    if (temp_letter_1 != -1) {
      if (paths_2[temp_letter_1] != -1) {
        int cost = paths_1[temp_letter_1] + paths_2[temp_letter_1];
        if (cost < min_cost || min_cost == -1) {
          min_cost = cost;
          letter_1 == temp_letter_1;
        }
      }
    }
    if (temp_letter_2 != -1) {
      if (paths_1[temp_letter_2] != -1) {
        int cost = paths_2[temp_letter_2] + paths_1[temp_letter_2];
        if (cost < min_cost || min_cost == -1) {
          min_cost = cost;
          letter_1 == temp_letter_2;
        }
      }
    }
    if (min_cost != -1) {
      return min_cost;
    }
  }
  return -1;
}

int main() {
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
    int current_cost = FindShortestPathBeetwenLetters(letter_1, letter_2, swaps);
    if (current_cost == -1) {
      impossible = true;
      break;
    }
    overall_cost += current_cost;
    word_1[i_letter] = static_cast<char>(letter_1 + 'a');

    /*std::map<int, int> shortest_path_from_1;
    FindShortestPath(shortest_path_from_1, swaps, busy, letter_1);
    ClearBusy(busy);
    std::cout << static_cast<char>(letter_1 + 'a') << '\n';
    for (std::pair<int, int> it : shortest_path_from_1) {
      std::cout << static_cast<char>(it.first + 'a') << " - " << it.second << '\n';
    }
    std::cout << "\n\n\n";*/
  }
  if (impossible) {
    std::cout << "-1\n";
  }
  else {
    std::cout << overall_cost << '\n' << word_1 << '\n';
  }
}