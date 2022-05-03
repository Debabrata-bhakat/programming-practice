#include <bits/stdc++.h>
#define ull unsigned long long 
#define ll long long
using lli = long long int;
using namespace std;
void solve();

int mod = 1e9+7;
int fact[200010];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    ull t;
    cin >> t;
    fact[0]=1;
    for (int i = 1; i < 200005; ++i)
    {
        fact[i] = (fact[i-1] * i) % mod; 
    }
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
    int n,m; cin>>n>>m;
    cout << ((1LL*fact[n+m] * modInv(fact[n]))%mod * modInv(fact[m]))%mod << endl;
}