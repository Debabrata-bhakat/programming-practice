#include <iostream>
using namespace std;

int last_index(int *arr, int size, int aim)
{
    //Base
    if (size == 0)
    {
        return -1;
    }

    if (arr[size - 1] == aim)
    {
        return size - 1;
    }
    int smallOutput = last_index(arr, size - 1, aim);
    if (smallOutput > -1)
    {
        return smallOutput;
    }
    else
    {
        return -1;
    }
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
    cout << last_index(arr, n, aim) << endl;
}