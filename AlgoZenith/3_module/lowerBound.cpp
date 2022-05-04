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

int check(int x, int a){
	return arr[x] >= a;
}

// 2 5 7 8 9 10
void solve(){
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int a;cin>>a;
	int lo=0,hi=n-1,ans=-1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(check(mid,a)){
			ans = mid; hi=mid-1;
		}else{
			lo=mid+1;
		}
	}
	cout << arr[ans] << endl;
}