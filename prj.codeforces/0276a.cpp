#include <iostream>

int main()
{
    int n, k;
    std::cin >> n >> k;
    int answer = -1e10;
    for (int i = 0; i < n; i += 1)
    {
        int f, t;
        int joy = -1e10;
        std::cin >> f >> t;
        if (t > k)
        {
            joy = f - (t - k);
        }
        else
        {
            joy = f;
        }
        if (joy > answer)
        {
            answer = joy;
        }
    }
    std::cout << answer << '\n';
}
