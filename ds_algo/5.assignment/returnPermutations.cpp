#include <iostream>
using namespace std;

int solve(string input, string *out){
    // Base case
    if (input.length()==1)
    {
        out[0] = input;
        return 1;
    }

    string *out1 = new string [1000];
    int smallOutput = solve(input.substr(1), out1);
    int ind = 0;
    for (int i = 0; i < smallOutput; i++)
    {
        string word = out1[i];
        for (int j = 0; j < smallOutput+1; j++)
        {
            string first_part = word.substr(0,j);
            string second_part = word.substr(j);
            string new_word = first_part + input[0] + second_part;
            out[ind++] = new_word;
        }
        
    }
    return ind;
    
}

int main(){
    string str;
    cin >> str;
    string *out = new string[1000];
    int res = solve(str, out);
    for (int i = 0; i < res; i++)
    {
        cout << out[i] << endl;
    }
    
}