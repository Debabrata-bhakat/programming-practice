#include <bits/stdc++.h>
using namespace std;

bool check(string s, int start, int end)
{
    //Base
    if (end - start < 0)
        return true;

    bool smallOutput = check(s, start + 1, end - 1);
    if ((s[start] == s[end]) and smallOutput)
        return true;
    else
        return false;
}

int main()
{
    string s;
    cin >> s;

    cout << check(s, 0, s.length() - 1) << endl;
}