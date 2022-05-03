#include <bits/stdc++.h>
#define ull unsigned long long 
#define ll long long
using lli = long long int;
using namespace std;
void solve();
void findFact();

int mod = 1e9+7;
const int N= 200010;
int fact[N];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    ull t;
    cin >> t;
    findFact();
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

void findFact(){
    fact[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        fact[i] = (int)((1LL*fact[i-1]*i)%mod);
    }
}

int diag(int n){
    int res = (int)((1LL*n*(n-3))%mod);
    res = (1LL*res*modInv(2))%mod;
    return res;
}

int intDiag(int n){
    int res = (int)(1LL*fact[n] * modInv(fact[4]) % mod);
    res = (int)(1LL*res*modInv(fact[n-4])%mod);
    return res;
}

void solve(){
    int n;cin>>n;
    cout << (1 + diag(n) + intDiag(n))%mod << endl;
}