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
	lli n;cin>>n; vector<lli> a(n),b(n); for(int i=0;i<n;i++) cin>>a[i]; for(int i=0;i<n;i++)cin>>b[i];
	sort(a.begin(),a.end()); sort(b.begin(),b.end());
	lli ans=0;
	for(int i=0;i<n;i++){
		ans += abs(a[i]-b[i]);
	}	
	cout << ans << endl;
}