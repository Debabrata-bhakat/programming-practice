#include <iostream>
using namespace std;

void solve(char s[])
{
    //Base
    if (s[0] == '\0')
        return;

    if (s[0] != 'x')
    {
        solve(s + 1);
    }
    else
    {
        int i = 1;
        for (; s[i] != '\0'; i++)
        {
            s[i - 1] = s[i];
        }
        s[i - 1] = s[i];
        solve(s);
    }
}

int main()
{
    char s[100];
    cin >> s;
    solve(s);
    cout << s << endl;
}