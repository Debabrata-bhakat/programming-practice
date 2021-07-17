#include <iostream>
using namespace std;

int subsequence(string str, string output[])
{
    // Base
    if (str.length() == 0)
    {
        output[0] = " ";
        return 1;
    }

    int lengthOfSmallOutput = subsequence(str.substr(1), output);
    //Add elements to the array
    for (int i = 0; i < lengthOfSmallOutput; i++)
    {
        output[i + lengthOfSmallOutput] = str[0] + output[i];
    }
    return lengthOfSmallOutput * 2;
}

int main()
{
    string s;
    cin >> s;
    string *arr = new string[1000];
    int lenOfSubs = subsequence(s, arr);
    for (int i = 0; i < lenOfSubs; i++)
    {
        cout << arr[i] << endl;
    }
}