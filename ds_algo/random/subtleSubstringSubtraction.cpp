// https://codeforces.com/contest/1673/problem/A
#include <bits/stdc++.h>
#define ull unsigned long long 
#define ll long long
using namespace std;
void solve();

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    cin >> t;
    // t=1;
    while(t--) solve();
}

void solve(){
    string s;cin>>s;
    int res1=0,res2=0;
    for (int i = 0; i < s.length(); ++i)
    {
        res1 += (s[i] - 'a' + 1);       
    }    
    if(s.length()%2==0){
        cout << "Alice " << res1 << '\n';
        return;
    }
    res2 = max(res1 - (s[0] - 'a' + 1), res1 - (s[s.length()-1] - 'a' + 1));
    int res3 = min((s[0] - 'a' + 1),(s[s.length()-1] - 'a' + 1));
    if(res2>res3){
        cout << "Alice " << res2-res3 << '\n';
    }else{
        cout << "Bob " << res3-res2 << '\n';
    }
}