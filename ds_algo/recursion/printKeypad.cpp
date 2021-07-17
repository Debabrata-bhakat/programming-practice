#include <iostream>
using namespace std;

void print_keypad(int input, string output, string keys[])
{
    if (input == 0)
    {
        cout << output << endl;
    }

    int curr_num = input % 10;
    string curr_arr = keys[curr_num];
    for (int i = 0; i < curr_arr.length(); i++)
    {
        print_keypad(input / 10, curr_arr[i] + output, keys);
    }
}

int main()
{
    int s;
    string output = "";
    cin >> s;
    string keys[] = {
        "",
        "",
        "ABC",
        "DEF",
        "GHI",
        "JKL",
        "MNO",
        "PQRS",
        "TUV",
        "WXYZ"};
    print_keypad(s, output, keys);
}