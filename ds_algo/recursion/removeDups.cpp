#include <iostream>
using namespace std;

void solve(char str[])
{
    if (str[0] == '\0')
    {
        return;
    }

    if (str[0] != str[1])
        solve(str + 1);

    if (str[0] == str[1])
    {
        int i = 1;
        for (; str[i] != '\0'; i++)
        {
            str[i - 1] = str[i];
        }
        str[i - 1] = str[i];
        solve(str);
    }
}

int main()
{
    char str[100];
    cin >> str;
    solve(str);
    cout << str << endl;
}