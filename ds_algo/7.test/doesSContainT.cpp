#include <iostream>
using namespace std;

bool solve(string s, string t){
    // Base
    if (s.length() == 1)
    {
        if(t == s){
            return true;
        }
    }
    if(t.length() == 0){
        return true;
    }
    while (s.length()>0)
    {
        if(t[0] == s[0]){
            break;
        }
        s = s.substr(1);
    }
    if(s.length() == 0){
        return false;
    }
    return solve(s.substr(1), t.substr(1));
}
int main(){
    string s,t;
    cin >> s;
    cin >> t;
    cout << solve(s,t) << '\n';
}