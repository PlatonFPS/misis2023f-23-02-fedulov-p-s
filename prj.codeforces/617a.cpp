#include <iostream>

int main()
{
    int distance;
    std::cin >> distance;
    int answer = 0;
    answer += distance / 5;
    if (distance % 5 != 0)
    {
        answer += 1;
    }
    std::cout << answer << '\n';
}
