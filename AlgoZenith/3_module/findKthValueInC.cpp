#include <bits/stdc++.h>
#define ull unsigned long long 
using lli = long long int;
using namespace std;
int mod = 1e9+7;
int n,k;
int arr[100100],brr[100100];
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
	lli ans=0;
	for (int i = 0; i < n; ++i)
	{
		ans += upper_bound(brr,brr+n,x-arr[i])-brr;
	}
	return ans < k;
}
void solve(){
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>brr[i];
	}
	sort(arr,arr+n); sort(brr,brr+n);
	int lo=0, hi=arr[n-1]+brr[n-1], ans = -1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(check(mid)){
			ans = mid;
			lo = mid+1;
		}else{
			hi = mid - 1;
		}
	}
	cout << ans +1 << endl;
}