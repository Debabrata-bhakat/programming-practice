#include <iostream>
using namespace std;

void solve(string input, string out){
    // Base case
    if(input.length() == 0){
        cout << out << endl;
        return;
    }
    if(input.length() == 1){
        char ch = input[0];
        string temp(1,char(int(ch) + 48));
        cout << out + temp << endl;
        return;
    }
    // Take just the first character
    char ch = input[0];
    string temp(1,char(int(ch) + 48));
    // out = out + temp;
    solve(input.substr(1), out+temp);

    // Take the first two character
    int temp_int = stoi(input.substr(0,2));
    if(temp_int <= 26){
        temp_int += 96;
        string temp2(1,char(temp_int));
        // out = out + temp2;
        solve(input.substr(2), out+temp2);
    }
    return;
}

int main(){
    string str;
    cin >> str;
    string out = "";
    solve(str, out);
}