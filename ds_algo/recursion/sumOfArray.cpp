#include <iostream>
using namespace std;

int sum_array(int *arr, int n)
{
    if (n == 0)
    {
        return 0;
    }
    int smallSum = sum_array(arr + 1, n - 1);
    return smallSum + arr[0];
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

    int sum = sum_array(arr, n);
    cout << sum << '\n';
}