#include <bits/stdc++.h>
using namespace std;

string solve(string s)
{
    // Base
    if (s.length() == 1)
        return s;

    string temp;

    string smallOutput = solve(s.substr(1));
    if (s[0] == smallOutput[0])
    {
        // return s[0] + "*" + smallOutput;
        temp.append(1, s[0]);
        temp.append(1, '*');
        temp.append(smallOutput);
    }
    else
    {
        // return s[0] + smallOutput;
        temp.append(1, s[0]);
        temp.append(smallOutput);
    }
    return temp;
}

int main()
{
    string s;
    cin >> s;
    cout << solve(s) << endl;
    // cout << string(s[0]) + s[1] << endl;
}