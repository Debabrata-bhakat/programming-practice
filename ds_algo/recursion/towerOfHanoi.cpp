#include <iostream>
using namespace std;

void solve(int n, char source, char aux, char dest)
{
    //Base
    if (n == 1)
    {
        cout << source << " " << dest << endl;
        return;
    }
    // move_from_source_to_aux
    solve(n - 1, source, dest, aux);
    cout << source << " " << dest << endl;
    solve(n - 1, aux, source, dest);
    return;
}
int main()
{
    int n;
    cin >> n;
    solve(n, 'a', 'b', 'c');
}