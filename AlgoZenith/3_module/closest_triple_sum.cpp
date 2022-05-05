#include <bits/stdc++.h>
#define ull unsigned long long 
using lli = long long int;
using namespace std;
int mod = 1e9+7;
void solve();
int n,x;
vector<lli> arr;
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
	cin>>n>>x;
	arr.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	sort(arr.begin(),arr.end());
	lli ans = 3e18;
	for (int j = 1; j < n-1; ++j)
	{
		int i = 0;
		int k = n-1;
		while(i<j && k>j){
			ans = min(ans, abs(arr[i]+arr[j]+arr[k]-x));
			if(arr[i]+arr[j]+arr[k]<x) i++;
			else k--;
		} 
	}
	cout << ans << endl;
}