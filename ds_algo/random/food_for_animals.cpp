// https://codeforces.com/contest/1675/problem/A
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
	int a,b,c,x,y; cin>>a>>b>>c>>x>>y;
	x = x-a, y=y-b;
	if(x<=0 and y<=0){
		cout << "YES\n";
		return;
	}
	else if(x<=0 and (y-c)<=0){
		cout << "YES\n"; return;
	}else if(y<=0 and (x-c)<=0){
		cout << "YES\n"; return;
	}else if(x>0 and y>0 and x+y-c<=0){
		cout << "YES\n"; return;
	}else{
		cout << "NO\n";
	}
}