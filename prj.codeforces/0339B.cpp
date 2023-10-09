#include <iostream>

int main() {
  long long road_lenght = 0;
  long long n_thing = 0;
  std::cin >> road_lenght >> n_thing;
  long long last_place = 1;
  long long time = 0;
  for (long long i_thing = 0; i_thing < n_thing; i_thing += 1) {
    long long thing = 0;
    std::cin >> thing;
    if (thing >= last_place) {
      time += thing - last_place;
    }
    else {
      time += thing + road_lenght - last_place;
    }
    last_place = thing;
  }
  std::cout << time << '\n';
}
