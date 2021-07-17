#include <iostream>
#include <string>
using namespace std;


int solve(string str, string *out){
    // Base case
    if(str.length() == 0){
        out[0] = "";
        return 1;
    }
    if(str.length()==1){
        char ch = str[0];
        string temp(1,char(int(ch) + 48));
        out[0] = temp;
        return 1;
    }

    // Take just the first number
    int res = 0;
    char curr1 = str[0];
    string *out1 = new string[1000];
    int smallOutput1 = solve(str.substr(1), out1);
    string curr1_to_char(1,char(int(curr1) + 48));
    for (int i = 0; i < smallOutput1; i++)
    {
        out[i] = curr1_to_char + out1[i];
    }
    res = res + smallOutput1;

    // Take the first two numbers
    int curr2_to_num = stoi(str.substr(0,2));
    string *out2 = new string[1000];
    if (curr2_to_num <= 26)
    {
        string curr2_to_str(1,char(curr2_to_num + 96));
        // string curr2_to_str = to_string(char(curr2_to_num + 96));
        int smallOutput2 = solve(str.substr(2), out2);
        for (int i = 0; i < smallOutput2; i++)
        {
            out[i+smallOutput1] = curr2_to_str + out2[i]; 
        }
        res = res + smallOutput2;
    }
    return res;
}

int main(){
    string s;
    cin >> s;
    string *out = new string[1000];
    int res = solve(s, out);
    for (int i = 0; i < res; i++)
    {
        cout << out[i] << '\n';
    }
    
    
}