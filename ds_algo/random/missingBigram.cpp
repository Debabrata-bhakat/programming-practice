// https://codeforces.com/contest/1618/problem/B
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
    int n; cin >> n;
    string res; cin >> res;
    char ch = res[1];
    int flag=0;
    for (int i = 1; i < n-2; i++)
    {
        string temp; cin >> temp;
        if(ch!=temp[0]){
            if(ch=='a') res += "b";
            else res+= "a";
            ch = res[res.length()-1];
            flag=1;
        }
        ch = temp[1];
        res += temp[1];
        // if(ch==temp[0]){
        //     continue;
        // }else{
        //     if(ch=='a') res += "b";
        //     else res+= "a";
        //     ch = res[res.length()-1];
        // }
    }
    if(flag==0) res+="b";
    cout << res << '\n';
}