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

vector<lli> subsetSum(vector<lli>& arr, lli m){
	int n = arr.size();
	vector<lli> ans;
	for(int i=0;i<(1<<n);i++){
		lli sum=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				sum+=(arr[j]%m);
			}
		}
		ans.push_back(sum);
	}
	sort(ans.begin(),ans.end());
	return ans;
}

void solve(){
	lli n,m;cin>>n>>m; vector<lli> arr(n); for(int i=0;i<n;i++)cin>>arr[i];
	vector<lli> left_arr,right_arr;
	for(int i=0;i<n;i++){
		if(i==0) left_arr.push_back(arr[i]); else right_arr.push_back(arr[i]);
	}
	lli ans=INT_MIN;
	vector<lli> s_a = subsetSum(left_arr,m), s_b = subsetSum(right_arr,m);
	for(int i=0;i<s_a.size();i++){
		lli req = (m-1-s_a[i]+m)%m;
		lli curr = upper_bound(s_b.begin(),s_b.end(),req) - s_b.begin() -1 ;
		if(curr<0) curr = s_b[s_b.size()-1];
		ans = max(ans,(s_a[i]+s_b[curr])%m);
	}
	cout << ans << endl;
}