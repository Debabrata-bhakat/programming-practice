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

int gcd(int a, int b){
	if(a==0 or b==0) return a^b;
	return __gcd(a,b);
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    // cin >> t;
    t=1;
    while(t--) solve();
}

vector<lli> pairSum(vector<lli>& arr){
	lli n = arr.size();
	vector<lli> ans;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ans.push_back(arr[i]+arr[j]);
		}
	}
	return ans;
}

void solve(){
	lli n,k;cin>>n>>k; vector<lli> arr(n); for(int i=0;i<n;i++) cin>>arr[i];	
	vector<lli> sa = pairSum(arr);
	unordered_map<lli,lli> mp;
	for(int i=0;i<sa.size();i++){
		if(mp[k-sa[i]]==1) {cout << "YES\n"; return;}
		mp[sa[i]]=1;
	}
	cout << "NO\n";
}