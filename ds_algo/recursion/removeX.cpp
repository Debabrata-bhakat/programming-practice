#include <bits/stdc++.h>
using namespace std;

string solve(string s)
{
    //Base
    if (s == "x")
        return "";
    if (s.length() == 1)
        return s;

    string smallOutput = solve(s.substr(1));

    if (s[0] == 'x')
        return smallOutput;
    else
        return s[0] + smallOutput;
}

int main()
{
    string s;
    cin >> s;
    cout << solve(s) << endl;
}