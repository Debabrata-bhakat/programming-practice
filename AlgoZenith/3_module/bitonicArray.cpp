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
	return arr[x] > arr[x-1];
}
void solve_2(int k, int se){
	// find in the first half of array
	int lo=0,hi=k,ans=-1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(arr[mid]==se){
			cout << mid + 1 << " ";
			break;
		}
		if(arr[mid] < se) lo = mid+1;
		else hi = mid-1;
	}
	lo=k+1,hi=n-1,ans=-1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(arr[mid]==se){
			cout << mid + 1 << " ";
			break;
		}
		if(arr[mid] > se) lo = mid+1;
		else hi = mid-1;
	}
	cout << endl;
}
void solve(){
	int q;
	cin >> n>>q;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int lo=1,hi=n-1,ans=0;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(check(mid)){
			ans = mid;
			lo = mid+1;
		}else{
			hi = mid-1;
		}
	}
	// K is found
	while(q--) {
		int se; cin>>se;
		solve_2(ans,se);
	}
}