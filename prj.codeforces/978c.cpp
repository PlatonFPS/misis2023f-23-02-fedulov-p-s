#include <iostream>
#include <vector>

int FindDormNumber(std::vector<long long>& dorms, long long flat)
{
    int l = -1;
    int r = dorms.size() - 1;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (dorms[m] < flat)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    return r;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<long long> dorms(n);
    std::cin >> dorms[0];
    for (int i = 1; i < n; i += 1)
    {
        std::cin >> dorms[i];
        dorms[i] += dorms[i - 1];
    }
    for (int i = 0; i < m; i++)
    {
        long long flat;
        std::cin >> flat;
        int dormNumber = FindDormNumber(dorms, flat);
        long long flatNumber = 0;
        if (dormNumber == 0)
        {
            flatNumber = flat;
        }
        else
        {
            flatNumber = flat - dorms[dormNumber - 1];
        }
        std::cout << dormNumber + 1 << ' ' << flatNumber << '\n';
    }
}