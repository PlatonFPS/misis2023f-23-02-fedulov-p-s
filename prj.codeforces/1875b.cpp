#include <iostream>
#include <string>

int main() {
  int amount_of_data_sets;
  std::cin >> amount_of_data_sets;
  for (int i_data_set = 0; i_data_set < amount_of_data_sets; i_data_set += 1) {
    long long m_apples = 0;
    long long g_apples = 0;
    long long rounds = 0;
    std::cin >> m_apples >> g_apples >> rounds;
    long long m_apple_max = -1;
    long long m_apple_min = -1;
    long long m_apple_sum = 0;
    for (long long i_apple = 0; i_apple < m_apples; i_apple += 1) {
      long long apple = 0;
      std::cin >> apple;
      if (apple > m_apple_max || m_apple_max == -1) {
        m_apple_max = apple;
      }
      if (apple < m_apple_min || m_apple_min == -1) {
        m_apple_min = apple;
      }
      m_apple_sum += apple;
    }
    long long g_apple_max = -1;
    long long g_apple_min = -1;
    long long g_apple_sum = 0;
    for (long long i_apple = 0; i_apple < g_apples; i_apple += 1) {
      long long apple = 0;
      std::cin >> apple;
      if (apple > g_apple_max || g_apple_max == -1) {
        g_apple_max = apple;
      }
      if (apple < g_apple_min || g_apple_min == -1) {
        g_apple_min = apple;
      }
      g_apple_sum += apple;
    }
    if (m_apple_min < g_apple_max) {
      m_apple_sum += g_apple_max - m_apple_min;
      g_apple_sum += m_apple_min - g_apple_max;
      if (m_apple_min < g_apple_min) {
        g_apple_min = m_apple_min;
      }
      if (g_apple_max > m_apple_max) {
        m_apple_max = g_apple_max;
      }
    }
    if (rounds % 2 == 0) {
      m_apple_sum += g_apple_min - m_apple_max;
      g_apple_sum += m_apple_max - g_apple_min;
    }
    std::cout << m_apple_sum << '\n';
  }
}
