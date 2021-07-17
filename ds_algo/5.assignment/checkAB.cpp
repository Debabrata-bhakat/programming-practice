#include <iostream>
using namespace std;

int solve(string s){
    // Base case
    if (s.length() == 1)
        return 1;
    if (s == "bb")
        return 1;
    if (solve(s.substr(1)) == 0)
    {
        return 0;
    }
    
    if(s[0] == 'a' and s.substr(1) == "bb"){
        return 1;
    }
    if(s.substr(0,2) == "bb" and s[3] == 'a'){
        return 1;
    }
    return 0;
}

int main(){
    string s;
    cin >> s;
    if(s[0] != 'a'){
        cout << "false" << endl;
        return 1;
    }
    int res = solve(s);
    if (res)
        cout<< "true" << endl;
    else
        cout << "false" << endl;
}