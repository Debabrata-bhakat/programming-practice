#include <iostream>
using namespace std;

void print_subs(string input, string output)
{
    // Base
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }

    print_subs(input.substr(1), output);
    print_subs(input.substr(1), output + input[0]);
}

int main()
{
    string input, output = "";
    cin >> input;
    print_subs(input, output);
}