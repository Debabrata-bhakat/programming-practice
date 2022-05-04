#include <bits/stdc++.h>
#define ull unsigned long long 
using lli = long long int;
using namespace std;
int mod = 1e9+7;
int n;
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
	return arr[x] >= arr[0];
}


// THINGS TO REMEMBER
// 1. Range
// 2. ans default value is what we want if the condition to update ans is never met
// 3. how to update lo and hi based on if we want first N or last Y
void solve(){
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int lo=0;
	int hi=n-1;
	int ans=0;

	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(check(mid)){
			lo = mid+1;
		}else{
			ans = mid;
			hi = mid-1;
		}
	}
	cout << ans << endl;
}