// https://codeforces.com/contest/1617/problem/C
#include <bits/stdc++.h>
#define ull unsigned long long 
#define ll long long
using namespace std;
void solve();
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}

void solve2(){
    ll n; cin >> n;
    vector<ll> a;
    for (ll i = 0; i < n; i++)
    {
        ll temp;cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    vector<ll> left;
    vector<ll> corr;
    ll max =0;
    for (ll i = 0; i < a.size(); i++)
    {
        if(a[i]<=n){
            corr.push_back(a[i]);
            max = a[i];
            continue;
        } 
        else left.push_back(a[i]);
    }
    

    for (int i = 0; i < corr.size(); i++)
    {
        if(corr[i]!=(i+1)){
            cout << "-1\n";
            return;
        }
    }
    

    ll res=0;
    for (ll i = 0; i < left.size(); i++)
    {
        ll flag = left[i] - (i+max+1);
        if(flag > (i+max)){
            res++;
        } else{
            cout << "-1\n";
            return;
        }
    }
    cout << res << '\n';
}

void solve(){
    ll n; cin >> n;
    vector<ll> a;
    for (ll i = 0; i < n; i++)
    {
        ll temp; cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(),a.end());
    unordered_map<ll,ll> seen;
    vector<ll> left_over_target, left_over_source;
    for (ll i = 0; i < a.size(); i++)
    {
        if(a[i]>n or seen.count(a[i])>0){
            left_over_source.push_back(a[i]);
        }else seen[a[i]]=1;
    }
    for (ll i = 1; i <= n; i++)
    {
        // check presence 
        if(seen.count(i)>0) continue;
        else{
            left_over_target.push_back(i);
        }   
    }
    ll res=0;
    // cout << "source\n";
    // for (int i = 0; i < left_over_source.size(); i++)
    // {
    //     cout << left_over_source[i] << " " ;
    //     cout << '\n';
    // }
    // cout << "target\n";
    // for (int i = 0; i < left_over_target.size(); i++)
    // {
    //     cout << left_over_target[i] << " " ;
    //     cout << '\n';
    // }
    for (ll i = 0; i < left_over_source.size(); i++)
    {
        if((left_over_source[i] - left_over_target[i])>left_over_target[i]) res++;
        else{
            cout << "-1\n";
            return;
        }
    }

    
    cout << res << '\n';
}