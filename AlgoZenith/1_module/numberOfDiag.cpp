#include <bits/stdc++.h>
#define ull unsigned long long 
#define ll long long
using lli = long long int;
using namespace std;
void solve();

int mod = 1e9+7;
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

lli binary_exponentiation(lli a, lli b,  lli mod){
    lli ans=1;
    while(b>0){
        if(b%2==1){
            ans = (ans*a) % mod;
        }
        a = (a*a) %mod;
        b/=2;
    }
    return ans;
}

int modInv(int a){
    return (int)(binary_exponentiation(a,mod-2,mod));
}

void solve(){
    int n;cin>>n;
    int res = (int)((1LL*n*(n-3))%mod);
    res = (1LL*res*modInv(2))%mod;
    cout << res << endl;
}
