#include <iostream>
using namespace std;

bool find_num(int *arr, int size, int aim)
{
    //Base
    if (size == 1)
    {
        if (arr[0] == aim)
        {
            return true;
        }
        else
            return false;
    }

    bool smallOutput = find_num(arr + 1, size - 1, aim);
    if (smallOutput || arr[0] == aim)
    {
        return true;
    }
    else
        return false;
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
    int target;
    cin >> target;
    cout << find_num(arr, n, target) << '\n';
}