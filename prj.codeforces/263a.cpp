#include <iostream>

int main()
{
    int answer = 0;
    for (int i = 0; i < 5; i += 1)
    {
        for (int j = 0; j < 5; j += 1)
        {
            bool b = 0;
            std::cin >> b;
            if (b)
            {
                answer = abs(i - 2) + abs(j - 2);
            }
        }
    }
    std::cout << answer << '\n';
}