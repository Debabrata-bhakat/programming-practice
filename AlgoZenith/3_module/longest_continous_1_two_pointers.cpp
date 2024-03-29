#include <bits/stdc++.h>
#define ull unsigned long long 
using lli = long long int;
using namespace std;
int mod = 1e9+7;
int n,k;
vector<int> arr;
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
		cin>> arr[i];
	}
	int ans=0,head=-1,tail=0,cnt0=0;
	while(tail<n){
		while(head+1<n && cnt0+(1-arr[head+1])<=k ){
			head++;
			cnt0+=(1-arr[head]);
		}
		ans = max(ans,head-tail+1);
		if(head>=tail){
			cnt0 -= (1-arr[tail]);
			tail++;
		}else{
			tail++;
			head = tail - 1;
		}
	}
	cout << ans << endl;
}