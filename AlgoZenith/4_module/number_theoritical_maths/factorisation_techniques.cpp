#include <bits/stdc++.h>
#define ull unsigned long long 
using lli = long long int;
using namespace std;
using ii = pair<long, long>;
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

bool is_prime(long long x){
	for(long long i=2;i*i<=x;i++){
		if(x%i==0) return 0;
	}
	return 1;
}

vector<long long> divisors(long long x){
	vector<long long> ans;
	for(long long i=1;i*i<=x;i++){
		if(x%i==0){
			ans.push_back(i);
			if(i*i!=x){
				ans.push_back(x/i);
			}
		}
	}
	return ans;
}

vector<ii> factors(long long x){
	vector<ii> ans;
	for(long long i=2;i*i<=x;i++){
		if(x%i==0){
			int cnt=0;
			while(x%i==0){
				cnt++;
				x/=i;
			}
			ans.push_back({i,cnt});
		}
	}
	if(x>1){
		ans.push_back({x,1});
	}
	return ans;
}

void solve(){
	int n;cin>>n;
	vector<ii> ans = factors(n);
	cout << n << " : ";
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	cout << endl;
}