#include <iostream>
using namespace std;

void solve(string input, string output){
    // Base case
    if (input.length()==0)
    {
        cout << output << endl;
        return;
    }

    // If output is empty
    string temp(1,input[0]);
    if(output.length() == 0){
        solve(input.substr(1), temp);
        return;
    }
    for (int i = 0; i < output.length()+1; i++)
    {
        char curr_word = input[0];
        string first_part = output.substr(0,i);
        string second_part = output.substr(i);
        string new_word = first_part + curr_word + second_part;
        solve(input.substr(1), new_word);
    }
    return;    
}

int main(){
    string str;
    cin >> str;
    solve(str, "");
}