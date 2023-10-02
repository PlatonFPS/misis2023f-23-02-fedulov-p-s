#include <iostream>

int main()
{
    int y;
    std::cin >> y;
    bool searching = 1;
    int i = y + 1;
    while(searching)
    {
        int t = i;
        int d = t % 10;
        t /= 10;
        int c = t % 10;
        t /= 10;
        int b = t % 10;
        t /= 10;
        int a = t;
        if (a != b && a != c && a != d)
        {
            if (b != c && b != d)
            {
                if (c != d)
                {
                    std::cout << i << '\n';
                    searching = 0;
                    continue;
                }
            }
        }
        i += 1;
    }
}