#include <iostream>
#include <cmath>
using namespace std;

double sum(int n)
{
    // cout << n << endl;
    //Base
    if (n == 0)
        return 1;
    double smallOutput = sum(n - 1);
    double series_sum = smallOutput + 1 / pow(2, n);
    // cout << "return " << series_sum << endl;
    return series_sum;
}

int main()
{
    int n;
    cin >> n;
    cout << sum(n) << endl;
}