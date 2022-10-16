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
    cin >> t;
    t=1;
    while(t--) solve();
}

void solve(){
	int n;cin>>n;
	vector<int> arr(n+1); arr[0]=0;
	for(int i=1;i<=n;i++) cin>> arr[i];
	int s;cin>>s;
	// vector<int> P(n+1), Q(n+1);
	// P[0]=0; Q[0]=0;
	// for(int i=1;i<=n;i++){
	// 	P[i] = arr[i]+P[i-1]; Q[i] = P[i]-s*i;
	// }
	// unordered_map<int,int> mp;
	// int res=0;
	// mp[0]=1;
	// for(int i=1;i<=n;i++){
	// 	int curr = Q[i];
	// 	res += mp[curr]; mp[curr]++;
	// }

	int res=0;
	unordered_map<int,int> mp; mp[0]=1; int sum=0, sum_avg;
	for(int i=1;i<=n;i++){
		sum+=arr[i]; sum_avg=sum-s*i;
		res+=mp[sum_avg]; mp[sum_avg]++;
	}
	cout << res << endl;


}