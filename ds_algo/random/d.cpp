// https://codeforces.com/contest/1618/problem/D
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
    int n,k; cin >> n >> k;
    vector<int> in;
    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        in.push_back(temp);
    }
    sort(in.begin(), in.end());
    stack<int> a;
    a.push(in[0]);
    for (int i = 1; i < n; i++)
    {
        if(in[i]!=a.top() and k>0){
            k--;
            a.pop();
        }else{
            a.push(in[i]);
        }
    }
    int res=0;
    while(k>0){
        int n1 = a.top(); a.pop();
        int n2 = a.top(); a.pop();
        if(n1==n2) res++;
    }
    while(a.size()>0){
        res += a.top(); a.pop();
    }
    cout << res << '\n';
}