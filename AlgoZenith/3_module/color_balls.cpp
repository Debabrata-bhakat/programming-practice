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

int check(int x, map<int,int> freq, int k){
	int usefull_balls = 0;
	for(auto i:freq){
		usefull_balls += min(x,i.second);
	}
	return usefull_balls >= x*k;
}

void solve(){
	int n,k;cin>>n>>k;
	int arr[n];
	map<int,int> freq;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		freq[arr[i]]++;
	}
	int lo=0,hi=n/k,ans=0;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(check(mid,freq,k)){
			ans = mid;
			lo = mid+1;
		}else{
			hi = mid-1;
		}
	}
	cout << ans << endl;
}