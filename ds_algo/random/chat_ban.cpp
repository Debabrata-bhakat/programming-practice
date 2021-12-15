// https://codeforces.com/contest/1612/problem/C
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

ull get(int x){
    ull res = 1;
    return res*x*(x+1)/2;
}

void solve(){
    ull k,x;
    cin >> k >> x;
    // no ban
    if( k*(k+1)-k <= x){
        cout << 2*k-1 << '\n';
        return;
    }
    
    ull l=1,r=2*k-1,res=2*k-1;
    bool over=false;
    while(l<=r){
        ull mid=(l+r)>>1;
        if(mid>=k){
            if(get(k) + get(k - 1) - get(2 * k - 1 - mid)>=x) over=true;
            else over=false;
        }else{
            if(get(mid)>=x) over=true;
            else over=false;
        }
        if(over){
            res=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout << res << '\n';
}

void solve2(){
    int a[] = {0,0,0,0,1,1,1,1,1,1};
    int size = 10,res=9;
    int l = 0,r = size-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid]==1){
            res = mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout << res << endl;
}
