// https://codeforces.com/contest/1675/problem/B#
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

int check(int n, int& prev){
	if(n<prev){
		prev = n; return 0;
	}
	if(prev<=0) return -1;
	int ans=0;
	while(n>=prev){
		n = n/2;
		ans++;
	}
	prev = n;
	return ans;
}

void solve(){
	int n;cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int prev=arr[n-1];
	int ans=0;
	for(int i=n-2;i>=0;i--){
		int temp=check(arr[i],prev);
		// cout << prev << endl;
		if(temp==-1){
			cout << "-1\n"; return;
		}
		ans += temp;
	}
	cout << ans << endl;
}