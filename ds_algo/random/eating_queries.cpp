// https://codeforces.com/contest/1676/problem/E
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

void solve(){
	int n,q;cin>>n>>q;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	sort(arr.begin(), arr.end(), greater<int>());
	for (int i = 1; i < n; ++i)
	{
		arr[i] += arr[i-1];
	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << arr[i] << " ";
	// }
	while(q--){
		int x;cin>>x;
		int pos = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
		if(pos == arr.size()) cout << "-1\n";
		else cout << pos+1 << endl;
	}
}