#include <iostream>
#include <map>

int main() {
  int n_data_set = 0;
  std::cin >> n_data_set;
  for (int i_data_set = 0; i_data_set < n_data_set; i_data_set += 1) {
    int n_robot = 0;
    std::cin >> n_robot;
    std::map<int, int> robots;
    for (int i_robot = 0; i_robot < n_robot; i_robot += 1) {
      int robot = 0;
      std::cin >> robot;
      robots[robot] += 1;
    }
    int prev_amount = -1;
    int prev_number = -1;
    bool answer = true;
    for (auto it : robots) {
      if (prev_amount == -1) {
        if (it.first != 0) {
          answer = false;
          break;
        }
        prev_number = it.first;
        prev_amount = it.second;
        continue;
      }
      if (it.first - prev_number > 1) {
        answer = false;
        break;
      }
      if (it.second > prev_amount) {
        answer = false;
        break;
      }
      prev_number = it.first;
      prev_amount = it.second;
    }
    std::cout << (answer ? "YES\n" : "NO\n");
  }
  return 0;
}