#include <iostream>
using namespace std;

void all_index(int *arr, int size, int aim, int *id)
{
    if (size == 0)
    {
        return;
    }

    all_index(arr + 1, size - 1, aim, id + 1);
    if (arr[0] == aim)
    {
        id[0] = 1;
    }
    return;
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

    int *id = new int[n];
    for (int i = 0; i < n; i++)
    {
        id[i] = 0;
    }
    all_index(arr, n, aim, id);
    for (int i = 0; i < n; i++)
    {
        if (id[i] != 0)
        {
            cout << i << " ";
        }
    }
}