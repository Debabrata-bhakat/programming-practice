// https://www.codechef.com/submit/WATESTCASES
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
	int n;cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	string s;cin>>s;
	int res = INT16_MAX;
	for(int i=0;i<n;i++){
		if(s[i]=='1') continue;
		res = min(res,arr[i]);
	}	
	cout << res<<endl;
}