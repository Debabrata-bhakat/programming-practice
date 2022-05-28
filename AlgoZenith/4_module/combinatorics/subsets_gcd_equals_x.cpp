#include <bits/stdc++.h>
#define ull unsigned long long 
using lli = long long int;
using namespace std;
int mod = 1e9+7;
void solve();
vector<int> divi[100001];
void pre(){
	for (int i = 1; i < 100000; ++i)
	{
		for (int j = 1; j < 100000; ++j)
		{
			divi[j].push_back(i);
		}
	}
}

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
    pre();
    int t;
    cin >> t;
    // t=1;
    while(t--) solve();
}



void solve(){
	int n;cin>>n;
	map<int,int> mp;
	for (int i = 0; i < n; ++i)
	{
		int x;cin>>x;
		mp[x]++;
	}
	int freq[100010];
	for(auto v:mp){
		for(auto x:div[v.first]){
			freq[x]+=v.second;
		}
	}
	for (int i = 1; i < 100000; ++i)
	{
		freq[i] = (binary_exponentiation(2,freq[i],mod) - 1 + mod)%mod;
	}
	for(int i=100000;i>=1;i--){
		for (int j = 2*i; j < 100000; j+=i)
		{
			freq[i] = (freq[i]-freq[j]+mod)%mod;
		}
	}


}