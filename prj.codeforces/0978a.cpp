#include <iostream>
#include <map>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::map<int, bool> uniqueNumbers;
    std::vector<int> numbers(n);
    std::vector<int> answer;
    for (int i = 0; i < n; i += 1)
    {
        std::cin >> numbers[i];
    }
    for (int i = numbers.size() - 1; i >= 0; i -= 1)
    {
        int t = numbers[i];
        if (uniqueNumbers[t]) continue;
        uniqueNumbers[t] = true;
        answer.push_back(t);
    }
    std::cout << answer.size() << '\n';
    for (int i = answer.size() - 1; i >= 0; i -= 1)
    {
        std::cout << answer[i] << ' ';
    }
}