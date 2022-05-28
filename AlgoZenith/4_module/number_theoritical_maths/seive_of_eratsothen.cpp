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

vector<int> seive(int n){
	vector<int> is_prime(n+1);
	for(int i=2;i<=n;i++) is_prime[i]=1;
	for(int i=2;i<=n;i++){
		if(is_prime[i]){
			for(long long j=1LL*i*i;j<=n;j+=i){
				is_prime[j]=0;
			}
		}
	}
	return is_prime;
}

void solve(){
	int n;cin>>n;
	vector<int> ans = seive(n);
	for(auto i : ans){
		cout << i << " " ;
	}
	cout << endl;
}