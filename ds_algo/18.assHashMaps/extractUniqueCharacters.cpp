#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string removeDups(string s){
    unordered_map<char,int> seen;
    string output="";
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        // check presence
        if(seen.count(c)>0) continue;
        else{
            output += c;
            seen[c] = 1;
        }
    }
    return output;
}

int main(){
    string s; cin >> s;
    cout << removeDups(s) << endl;
}