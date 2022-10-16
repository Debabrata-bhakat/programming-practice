#include <bits/stdc++.h>
#define ull unsigned long long 
using lli = long long int;
using namespace std;
int mod = 1e9+7;
void solve();
// calculate a^b mod 10^9+7
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

int gcd(int a, int b){
	if(a==0 or b==0) return a^b;
	return __gcd(a,b);
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    cin >> t;
    // t=1;
    while(t--) solve();
}

void solve(){
	int n,m,sx,sy,d;cin>>n>>m>>sx>>sy>>d;
	if(abs(sx-n)+abs(sy-m)<=d) {cout << "-1\n"; return;}	
	if(abs(sx-1)<=d and abs(sy-1)<=d) {cout << "-1\n"; return;}
	if(abs(sy-1)<=d and abs(m-sy)<=d) {cout << "-1\n"; return;}
	if(abs(sx-n)<=d and abs(m-sy)<=d) {cout << "-1\n"; return;}
	if(abs(sx-1)<=d and abs(sx-n)<=d) {cout << "-1\n"; return;}
	int res = abs(n-1) + abs(m-1);
	cout << res << endl;
}