// https://codeforces.com/contest/1620/problem/0
#include <bits/stdc++.h>
#define ull unsigned long long 
using namespace std;
void solve();
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}

void solve(){
    string s; cin >> s;
    string temp="";
    int flag = 0;
    // EEEN
    for (int i = 0; i < s.size()-1; i++)
    {
        if(s[i]=='N') flag = 1;
    }
    if(flag==0 and s[s.size()-1]=='N'){
        cout << "NO\n";
        return;
    }
    // NEEEEE
    flag=0;
    temp="";
    for (int i = 1; i < s.size(); i++)
    {
        if(s[i]=='N') flag=1;
    }
    if(flag==0 and s[0]=='N'){
        cout << "NO\n";
        return;
    }
    
    cout << "YES\n";
}