#include <iostream>
using namespace std;

void print_num(int n)
{
    if (n == 1)
    {
        cout << "1 ";
        return;
    }
    print_num(n - 1);
    cout << n << " ";
}

int main()
{
    int n;
    cin >> n;
    print_num(n);
}