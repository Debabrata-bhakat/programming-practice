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
    // t=1;
    while(t--) solve();
}

vector<lli> subsetSum(vector<lli>& arr){
	int n = arr.size();
	vector<lli> ans;
	for(int i=0;i<(1<<n);i++){
		int sum=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				sum+=arr[j];
			}
		}
		ans.push_back(sum);
	}
	sort(ans.begin(),ans.end());
	return ans;
}

void solve(){
	lli n,x;cin>>n>>x;
	vector<lli> arr(n); for(int i=0;i<n;i++) cin>>arr[i];
	vector<lli> arr_1, arr_2;
	for(int i=0;i<n;i++){
		if(i%2==0) arr_1.push_back(arr[i]);
		else arr_2.push_back(arr[i]);
	}
	vector<lli> s_a = subsetSum(arr_1), s_b = subsetSum(arr_2);
	lli res=0;
	for(int i=0;i<s_a.size();i++){
		lli req = x-s_a[i];
		res += upper_bound(s_b.begin(),s_b.end(),req) - s_b.begin();
	}
	cout << res << '\n';
}