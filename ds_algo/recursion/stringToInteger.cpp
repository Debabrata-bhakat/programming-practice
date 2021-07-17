#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    //Base
    char ch = s[s.length() - 1];
    int temp = ch - 48;
    if (s.length() == 1)
    {
        return temp;
    }

    int smallOutput = solve(s.substr(0, s.length() - 1));
    return smallOutput * 10 + temp;
}

int main()
{
    string s;
    cin >> s;
    cout << solve(s) << endl;
}