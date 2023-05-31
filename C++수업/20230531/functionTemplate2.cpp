#include <iostream>
using namespace std;

template <typename T>
T Add(T arr[], int len)
{
    T sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6};
    long arr2[] = {1, 4, 9, 16, 25, 36};

    cout << Add(arr1, 6) << endl;
    cout << Add(arr2, 6) << endl;
}