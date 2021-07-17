#include <iostream>
using namespace std;

int solve(int s, string output[], string keys[])
{
    // Base
    if (s == 0)
    {
        output[0] = "";
        return 1;
    }

    int smallOutputSize = solve(s / 10, output, keys);
    int curr = s % 10;
    string curr_array = keys[curr];
    int len = curr_array.length();
    // Make copies
    // for (int i = 0; i < len; i++)
    // {
    //     for (int j = i * smallOutputSize; j < (i + 1) * smallOutputSize; j++)
    //     {
    //         output[j] = output[j] + curr_array[i];
    //     }
    // }
    for (int i = smallOutputSize; i < smallOutputSize * len; i++)
    {
        output[i] = output[i % len];
    }

    //add element at end
    int in = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < smallOutputSize; j++)
        {
            output[in] = output[in] + curr_array[i];
            in++;
        }
    }

    return smallOutputSize * len;
}

int main()
{
    int s;
    cin >> s;
    string *arr = new string[1000];
    string keys[] = {
        "",
        "",
        "ABC",
        "DEF",
        "GHI",
        "JKL",
        "MNO",
        "PQRS",
        "TUV",
        "WXYZ"};
    int outputSize = solve(s, arr, keys);
    for (int i = 0; i < outputSize; i++)
    {
        cout << arr[i] << "\n";
    }
};
