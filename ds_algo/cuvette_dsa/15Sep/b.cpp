#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, ans = "";
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        // if ch is equal to last and second last character
        if(ch == ans[ans.size()-1] and ch == ans[ans.size()-2]) continue;
        // if ch is equal to last character and the two elements before them are equal
        if(ans.size() > 2 and ch == ans[ans.size()-1] and ans[ans.size()-2] == ans[ans.size()-3]) continue;
        ans += ch;
    }
    cout << ans << endl;
}