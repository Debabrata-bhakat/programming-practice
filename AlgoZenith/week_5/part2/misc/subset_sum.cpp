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

vector<int> subsetSum(int n, vector<int>& a){
	vector<int> ans;
	for(int mask=0;mask<(1<<n);mask++){
		int subSum = 0;
		for(int j=0;j<n;j++){
			if(mask&(1<<j)){
				subSum+=a[j];
			}
		}
		ans.push_back(subSum);
	}
	sort(ans.begin(), ans.end());
	return ans;
}

void solve(){
	vector<int> v = {1,2,3}; int n=3,X=5;
	vector<int> a,b;
	for(int i=0;i<n;i++){
		if(i%2==0) a.push_back(v[i]);
		else b.push_back(v[i]);
	}
	auto Sa = subsetSum(a.size(),a);
	auto Sb = subsetSum(b.size(),b);
	long long ans=0;
	for(auto v:Sa){
		ans+=upper_bound(Sb.begin(), Sb.end(), X-v )-Sb.begin();
	}
	cout << ans;
}