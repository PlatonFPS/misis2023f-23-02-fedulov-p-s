#include <iostream>
#include <vector>

int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i += 1)
    {
        int n;
        std::cin >> n;
        std::vector<int> answer;
        if (n > 10)
        {
            int t = n % 10;
            if (t != 0)
            {
                answer.push_back(t);
            }
            n -= t;
            if (n > 100)
            {
                int t = n % 100;
                if (t != 0)
                {
                    answer.push_back(t);
                }
                n -= t;
                if (n > 1000)
                {
                    int t = n % 1000;
                    if (t != 0)
                    {
                        answer.push_back(t);
                    }
                    n -= t;
                }
            }
        }
        answer.push_back(n);
        std::cout << answer.size() << '\n';
        for (int a : answer)
        {
            std::cout << a << ' ';
        }
        std::cout << '\n';
    }
}