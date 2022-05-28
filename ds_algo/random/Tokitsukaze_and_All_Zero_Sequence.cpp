// https://codeforces.com/contest/1678/problem/A
#include <bits/stdc++.h>
#define ull unsigned long long 
using lli = long long int;
using namespace std;
int mod = 1e9+7;
void insert(int* freq,int x, int& cntDistinct){
	freq[x]++;
	if(freq[x]==1) cntDistinct++;
}
void remove(int* freq, int x, int& cntDistinct){
	freq[x]--;
	if(freq[x]==0) cntDistinct--;
}
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
	int n,cntDistinct=0;cin>>n;
	int arr[n];
	int freq[110];
	for (int i = 0; i < 110; ++i)
	{
		freq[i]=0;
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		insert(freq, arr[i], cntDistinct);
	}
	int ans=0;
	for (int i = 1; i < 110; ++i)
	{
		if(freq[i]==0 or freq[i]==1) continue;
		ans += freq[i];
		freq[i]=0;
	}
	int rem=0;
	for (int i = 1; i < 110; ++i)
	{
		if(freq[i]==1) rem++;
	}
	if(freq[0]>0){
		ans += rem;
	}else{
		if(rem == n) ans += rem+1;
		else ans += rem; 
	}
	cout << ans << endl;
}