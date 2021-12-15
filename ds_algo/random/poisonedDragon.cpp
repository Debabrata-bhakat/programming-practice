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

bool check(vector<ull> a, ull k, ull h){
    ull sum=0;
    for (ull i = 1; i < a.size(); i++)
    {
        sum += min(k, a[i]-a[i-1]);
    }
    sum+=k;
    return (h<=sum);
}

void solve(){
    ull n, h; cin >> n >> h;
    vector<ull> a;
    for (ull i = 0; i < n; i++)
    {
        ull temp; cin >> temp;
        a.push_back(temp);
    }
    ull l = 1, r = 1e18;
    while(l<=r){
        ull mid = (l+r)/2;
        if(check(a,mid,h)) r=mid-1;
        else l=mid+1;
    }   
    cout << (r+1) << '\n';
}