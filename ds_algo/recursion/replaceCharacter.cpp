#include <iostream>
using namespace std;

void solve(char s[], char c1, char c2)
{
    // Base
    if (s[0] == '\0')
        return;

    if (s[0] == c1)
    {
        s[0] = c2;
    }
    solve(s + 1, c1, c2);
}

int main()
{
    char str[100];
    char c1, c2;
    cin >> str;
    cin >> c1;
    cin >> c2;
    solve(str, c1, c2);
    cout << str << endl;
}