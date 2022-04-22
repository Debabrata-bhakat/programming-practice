// https://codeforces.com/contest/1617/problem/A
#include <bits/stdc++.h>
#define ull unsigned long long 
using namespace std;
void solve();
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    ull t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}

void sortString(string &str)
{
   sort(str.begin(), str.end());
}

void solve(){
    vector<string> per;
    per.push_back("abc");
    per.push_back("acb");
    per.push_back("bac");
    per.push_back("bca");
    per.push_back("cab");
    per.push_back("cba");
    string s; cin >> s;
    string t; cin >> t;
    string res="";
    string s_a="", s_b="", s_c="", s_z="";
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='a') s_a+=s[i];
        else if(s[i]=='b') s_b+=s[i];
        else if(s[i]=='c') s_c+=s[i];
        else s_z+=s[i];
    }
    sortString(s_z);
    // if either of string is empty this is smallest string
    if(s_a.length()==0 or s_b.length()==0 or s_c.length()==0){
        res=s_a+s_b+s_c+s_z;
        cout << res << '\n';
        return;
    }

    // get smallest permutation of t
    for (int i = 0; i < per.size(); i++)
    {
        if(t!=per[i]){
            t=per[i];
            break;
        }
    }
    

    for (int i = 0; i < t.size(); i++)
    {
        if(t[i]=='a') res+=s_a;
        else if(t[i]=='b') res+=s_b;
        else if(t[i]=='c') res+=s_c;
    }
    
    res+=s_z;
    cout << res << '\n';

}