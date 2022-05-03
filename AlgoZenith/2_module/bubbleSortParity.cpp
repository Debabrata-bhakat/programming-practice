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
void find_inv(vector<int> &a, int &ans){
	int n = a.size();
	if(n==1) return;
	vector<int> b1,b2,merged;
	for (int i = 0; i < n/2; ++i)
	{
		b1.push_back(a[i]);
	}
	for (int i = n/2; i < n; ++i)
	{
		b2.push_back(a[i]);
	}
	find_inv(b1,ans); find_inv(b2,ans);
	// Merge
	int i=0,j=0,k=0;
	while(i<b1.size() and j<b2.size()){
		if(b1[i]<=b2[j]){
			a[k++] = b1[i++];
		}else{
			a[k++] = b2[j++];
			ans += (b1.size() - i);
		}
	}
	while(i<b1.size()) a[k++] = b1[i++];
	while(j<b2.size()) a[k++] = b2[j++];
}

void solve(){
	int n;cin>>n;
	int ans=0;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	find_inv(a,ans);
	cout << (ans&1)  << endl;
}