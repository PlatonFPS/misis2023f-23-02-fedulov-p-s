#include <iostream>
#include <vector>

int main()
{
    std::vector<int> path(200);
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i += 1)
    {
        for (int j = 0; j < path.size(); j += 1)
        {
            path[j] = -1;
        }
        int n;
        std::cin >> n;
        for (int j = 0; j < n; j += 1)
        {
            int d, s;
            std::cin >> d >> s;
            d -= 1;
            if (path[d] == -1 || path[d] > s)
            {
                path[d] = s;
            }
        }
        int turnPoint = 500;
        for (int j = 0; j < path.size(); j += 1)
        {
            if (path[j] == -1) continue;
            if (j == turnPoint) break;
            int temp = j + (path[j] - 1) / 2;
            if (temp < turnPoint)
            {
                turnPoint = temp;
            }
        }
        std::cout << turnPoint + 1 << '\n';
    }
}
