#include <bits/stdc++.h>
#define ull unsigned long long 
using lli = long long int;
using namespace std;
int mod = 1e9+7;
int n,k;
vector<int> arr;
vector<int> preFix;
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
	cin>>n>>k;
	arr.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		preFix[i] = 1 - arr[i];
		if(i) preFix[i] += preFix[i-1];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int temp = upper_bound(preFix.begin()+i, preFix.end(), k+(i>0?preFix[i-1]:0)) - (preFix.begin()+i);
		ans = max(ans,temp);
	}
	cout << ans << endl;
}