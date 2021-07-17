#include <iostream>
using namespace std;

int sum_of_digits(int n)
{
    //Base
    if (n == 0)
        return 0;
    int smallOutput = sum_of_digits(n / 10);
    return smallOutput + n % 10;
}

int main()
{
    int n;
    cin >> n;
    cout << sum_of_digits(n) << endl;
}