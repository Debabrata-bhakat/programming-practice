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
void ban(ull i){
    cout << i << '\n';
}

void solve(){
    ull k,x;
    cin >> k >> x;
    // no ban
    if( k*(k+1)-k <= x){
        cout << 2*k-1 << '\n';
        return;
    }
    ull sum=0;
    ull c = 0;

    ull low = 1;
    ull high = k;
    ull mid;
    while (low<=high){
        mid = (high+low)/2;
        if(mid*(mid+1)/2>=x){
            ban(mid);
            return;
        }
    } 

    for (ull i = 1; i <= k; i++)
    {
        sum += i;
        c++;
        if(sum>=x){
            ban(c);
            return;
        }
    }
    for (ull i = k-1; i >= 1; i--)
    {
        sum+=i;
        c++;
        if(sum>=x){
            ban(c);
            return;
        }
    }
    
}
