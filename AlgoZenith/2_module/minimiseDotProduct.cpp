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

bool cmp(int a, int b){
    return (a>b);
}

void solve(){
    int n;cin>>n;
    vector<int> v (n),w(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>v[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin>>w[i];
    }
    sort(v.begin(),v.end());
    sort(w.begin(),w.end(),cmp);
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += v[i]*w[i];
    }
    cout << ans << endl;
}