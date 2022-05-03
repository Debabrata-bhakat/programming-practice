#include <bits/stdc++.h>
#define ull unsigned long long 
#define ll long long
// #define mod 1e9+7
using namespace std;
using lli = long long int;
int mod = 1e9+7;
void solve();
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

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    // cin >> t;
    t=1;
    while(t--) solve();
}

int find_dig(int n){
	int ans=0;
	while(n>0){
		ans++; n/=10;
	}
	return ans;
}

int karatsuba(int x, int y){
	int n = find_dig(max(x,y));
	if(n==1 or n==0) return x*y;
	int power_nby2 = (int)(binary_exponentiation(10,n/2,mod));
	int power_n = (int)(binary_exponentiation(10,n,mod));
	int a = x / power_nby2;
	int b = x % power_nby2;
	int c = y / power_nby2;
	int d = y % power_nby2;
	int ac = karatsuba(a,c), bd = karatsuba(b,d);
	int ac_plus_bd = karatsuba(a+b,c+d) - ac - bd;
	return (power_n*ac + power_nby2*ac_plus_bd + bd);
	// return 2;
}

void solve(){
	int x,y;cin>>x>>y;
	cout << karatsuba(x,y) << endl;
}