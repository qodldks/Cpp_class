#include <iostream>

int main()
{
    int str[5];
    int sum;
    for (int i = 0; i < 5; i++)
        std::cin >> str[i];
    for (int i = 0; i < 5; i++)
        sum+=str[i];
    std::cout << sum;
    return 0;
}