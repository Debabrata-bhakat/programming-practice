#include <iostream>
using namespace std;

int solve(string str)
{
    // Base
    if (str.length() == 0)
    {
        return 1;
    }

    int res1 = 0;

    if (str == "a" or str == "aa" or str == "abb" or str == "bb" or str == "bba")
        return 1;
    // Second case
    if (str.substr(0, 1) == "a")
    {
        if (str.substr(1, 1) == "a" or str.substr(1, 2) == "bb")
            res1 = 1;
    }
    // Third case
    if (str.substr(0, 2) == "bb" and str.substr(1, 1) == "a")
        res1 = 1;

    int res2 = solve(str.substr(1));
    return res1 and res2;
}

int main()
{
    string str;
    cin >> str;
    if (str.substr(0, 1) != "a")
    {
        cout << "false\n";
        return 1;
    }
    int ans = solve(str);
    if (ans = 1)
        cout << "true\n";
    else
        cout << "false\n";
}