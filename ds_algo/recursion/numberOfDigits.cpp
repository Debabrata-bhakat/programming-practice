#include <iostream>
using namespace std;

int digits(int n)
{
    if (n / 10 == 0)
    {
        return 1;
    }
    int smallOutput = digits(n / 10);
    return 1 + smallOutput;
}

int main()
{
    int n;
    cin >> n;
    cout << digits(n) << '\n';
}