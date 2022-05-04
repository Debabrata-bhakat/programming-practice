#include <bits/stdc++.h>
#define ull unsigned long long 
using lli = long long int;
using namespace std;
int mod = 1e9+7;
int n; int k;
int arr[100100];
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
int check(int x){
	int need = 0;
	for (int i = 1; i < n; ++i)
	{
		int diff = arr[i] - arr[i-1];
		need += (diff+x-1)/x - 1;
	}
	return need<=k;
}
void solve(){
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int lo=1,hi=1e9,ans=1e9;
	while(lo<=hi){
		int mid = (hi+lo)/2;
		if(check(mid)){
			ans = mid;
			hi = mid-1;
		}else{
			lo = mid + 1;
		}
	}
	cout << ans << endl;
}