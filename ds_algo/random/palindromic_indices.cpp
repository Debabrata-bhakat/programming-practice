// https://codeforces.com/contest/1682/problem/A
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
	int n;cin>>n;
	string s;cin>>s;
	int ans=0;
	if(n%2==1){
		ans++;
		int mid = n/2;
		char ch = s[mid];
		// go right
		int temp = mid;
		while(temp+1<n and s[temp+1]==ch) {
			temp++; ans++;
		}
		temp = mid;
		while(temp-1>=0 and s[temp-1]==ch) {
			temp--; ans++;
		}
	}else{
		ans+=2;
		int mid_right = n/2;
		int mid_left = mid_right-1;
		char ch = s[mid_right];
		while(mid_right+1<n and s[mid_right+1]==ch) {
			mid_right++; ans++;
		}
		while(mid_left-1>=0 and s[mid_left-1]==ch){
			mid_left--; ans++;
		}
	}
	cout << ans << endl;
}