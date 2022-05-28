// https://codeforces.com/contest/1670/problem/A
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
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int neg=0;
	for (int i = 0; i < n; ++i)
	{
		if(arr[i]<0)neg++;
	}
	for (int i = 0; i < n; ++i)
	{
		arr[i] = abs(arr[i]);
		if(neg>0){
			arr[i] = -arr[i];
			neg--;
		}
	}
	if(!is_sorted(arr,arr+n)) cout << "NO\n";
	else cout << "YES\n";
}