#include <iostream>

int main() {
  int n_data_set = 0;
  std::cin >> n_data_set;
  for (int i_data_set = 0; i_data_set < n_data_set; i_data_set += 1) {
    int n_men = 0;
    std::cin >> n_men;
    int polikarp_strenght = 0;
    int polikarp_stamina = 0;
    std::cin >> polikarp_strenght >> polikarp_stamina;
    int weight = polikarp_strenght;
    for (int i_men = 1; i_men < n_men; i_men += 1) {
      int strenght = 0;
      int stamina = 0;
      std::cin >> strenght >> stamina;
      if (strenght >= polikarp_strenght && stamina >= polikarp_stamina) {
        weight = -1;
      }
    }
    std::cout << weight << '\n';
  }
  return 0;
}