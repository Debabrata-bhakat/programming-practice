#include <iostream>
using namespace std;

int find_in(int *arr, int size, int full_size, int aim)
{
    //Base
    if (size == 1)
    {
        if (arr[0] == aim)
            return full_size - size;
        else
            return -1;
    }
    if (arr[0] == aim)
        return full_size - size;
    else if (find_in(arr + 1, size - 1, full_size, aim) > -1)
        return find_in(arr + 1, size - 1, full_size, aim);
    else
        return -1;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int aim;
    cin >> aim;
    cout << find_in(arr, n, n, aim) << '\n';
}