#include <iostream>
using namespace std;

int partition(int arr[], int si, int ei)
{
    int pivot = arr[si];
    //Find number of elements smaller than pivot
    int count = 0;
    for (int i = si + 1; i <= ei; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    //Place pivot at correct position
    int temp = arr[si + count];
    arr[si + count] = arr[si];
    arr[si] = temp;

    int i = si;
    int j = si + count + 1;
    while (i < si + count and j <= ei)
    {
        if (arr[i] < pivot)
        {
            i++;
        }
        else if (arr[j] > pivot)
        {
            j++;
        }
        else
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j++;
        }
    }
    return count + si;
}

void quickSort(int arr[], int si, int ei)
{
    // Base
    if (si >= ei)
    {
        return;
    }

    int pivot = partition(arr, si, ei);
    quickSort(arr, si, pivot - 1);
    quickSort(arr, pivot + 1, ei);
    return;
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
    // int center = partition(arr, 0, size - 1);
    quickSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}