#include <iostream>

int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i += 1)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        double n = double(a + b) / 2.0;
        double m = n - a;
        if (m < 0)
        {
            m = -m;
        }
        int answer = int(m / c);
        if (m - answer * c > 0.1)
        {
            answer += 1;
        }
        std::cout << answer << '\n';
    }
}