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

lli check(lli x,lli s){
	lli sum=0;
	lli tempx = x;
	while(tempx>0){
		sum += (tempx%10);
		tempx /= 10;
	}
	return x-sum>=s;
}

void solve(){
	lli n,s; cin>>n>>s;
	lli lo = 1,hi=n,ans=n+1;
	while(lo<=hi){
		lli mid = (lo+hi)/2;
		if(check(mid,s)){
			ans = mid;
			hi = mid-1;
		}else{
			lo = mid+1;
		}
	}
	cout << n-ans+1 << endl;
}