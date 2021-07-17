#include <bits/stdc++.h>
using namespace std;

string replace(string s)
{
    // cout << "string recived: " << s << endl;
    //Base
    if (s.length() == 1)
        return s;

    if (s == "pi")
    {
        // cout << "here" << endl;
        return "3.14";
    }
    string smallOutput = replace(s.substr(1));
    // cout << "string from recurseion : " << smallOutput << endl;
    if (s[0] == 'p' and smallOutput[0] == 'i')
    {
        return "3.14" + smallOutput.substr(1);
    }
    else
        return s[0] + smallOutput;
}

int main()
{
    string s;
    cin >> s;
    cout << replace(s) << endl;
}