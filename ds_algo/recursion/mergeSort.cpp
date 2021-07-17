#include <iostream>
using namespace std;

void merge(int arr[], int si, int ei)
{
    // Base
    if (si >= ei)
        return;

    int mid = (si + ei) / 2;
    merge(arr, si, mid);
    merge(arr, mid + 1, ei);

    int *new_arr = new int[ei - si + 1];
    int i = si;
    int j = mid + 1;
    for (int k = 0; k < ei - si + 1; k++)
    {
        if (i <= mid and j <= ei)
        {
            if (arr[i] < arr[j])
                new_arr[k] = arr[i++];
            else
                new_arr[k] = arr[j++];
        }
        else if (i == mid + 1)
        {
            new_arr[k] = arr[j++];
        }
        else
        {
            new_arr[k] = arr[i++];
        }
    }
    for (int k = 0; k < ei - si + 1; k++)
    {
        arr[k + si] = new_arr[k];
    }
}

int main()
{
    int size;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    merge(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
}