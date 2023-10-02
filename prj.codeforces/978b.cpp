#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int answer = 0;
    int xCount = 0;
    for (int i = 0; i < n; i += 1)
    {
        char c;
        std::cin >> c;
        if (c == 'x')
        {
            xCount += 1;
        }
        else
        {
            if (xCount >= 3)
            {
                answer += xCount - 2;
            }
            xCount = 0;
        }
    }
    if (xCount >= 3)
    {
        answer += xCount - 2;
    }
    xCount = 0;
    std::cout << answer << '\n';
}