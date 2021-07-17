#include <iostream>
using namespace std;

int multiply(int m, int n)
{
    //Base
    if (n == 0)
    {
        return 0;
    }
    int smallOutput = multiply(m, n - 1);
    return smallOutput + m;
}

int main()
{
    int m, n;
    cin >> m;
    cin >> n;
    cout << multiply(m, n) << endl;
}