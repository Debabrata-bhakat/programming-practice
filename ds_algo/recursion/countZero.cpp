#include <iostream>
using namespace std;

int noOfZeroes(int n)
{
    //Base
    if (n == 0)
        return 0;
    int smallOutput = noOfZeroes(n / 10);
    int digit = n % 10;
    int sum = 0;
    if (digit == 0)
        sum++;
    return sum + smallOutput;
}

int main()
{
    int n;
    cin >> n;
    cout << noOfZeroes(n) << endl;
}