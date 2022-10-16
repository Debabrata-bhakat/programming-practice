// https://codeforces.com/contest/1715/problem/C
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
    // cin >> t;
    t=1;
    while(t--) solve();
}

void solve(){
	lli n,m;cin>>n>>m;
	vector<lli> arr(n+1);
	for(lli i=1;i<=n;i++){
		cin>> arr[i];
	}	
	lli ans = n*(n+1)/2;
	// cout << ans << endl;
	for(lli i=1;i<n;i++){
		ans += (arr[i]!=arr[i+1])*(n-i)*i;
		// cout << ans << endl;
	}
	// cout << ans << endl;
	// cout << "lsdkjf\n";
	while(m--){
		lli i,x;cin>>i>>x;
		ans -= (arr[i]!=arr[i+1])*(n-i)*i;
		ans -= (arr[i]!=arr[i-1])*(n-i+1)*(i-1);
		arr[i]=x;
		ans += (arr[i]!=arr[i+1])*(n-i)*i;
		ans += (arr[i]!=arr[i-1])*(n-i+1)*(i-1);
		cout << ans << endl;
	}
}