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

lli check1(lli mid, lli i, vector<lli>& a1, vector<lli>& a2){
	return a1[i]<=a2[mid];
}

lli check2(lli mid, lli i, vector<lli>& a1, vector<lli>& a2){
	return a1[mid]<=a2[i];
}

void solve(){
	lli n;cin>>n;
	vector<lli> arr1(n),arr2(n); 
	for(lli i=0;i<n;i++) cin>>arr1[i]; for(lli i=0;i<n;i++) cin>>arr2[i];
	vector<lli> min_arr, max_arr; 
	for(lli i=0;i<n;i++){
		lli lo=0,hi=i,ans=i;
		while(lo<=hi){
			lli mid = (lo+hi)/2;
			if(check1(mid,i,arr1, arr2)){
				ans = mid; hi = mid-1;
			}else{
				lo = mid+1;
			}
		}
		min_arr.push_back(arr2[ans]-arr1[i]);
	}	
	for(auto x:min_arr) cout << x << " ";
	cout << endl;	
	for(lli i=0;i<n;i++){
		lli lo=i,hi=n-1,ans=i;
		while(lo<=hi){
			lli mid = (lo+hi)/2;
			if(check2(mid,i,arr1,arr2)){
				ans = mid; lo=mid+1;
			}else{
				hi=mid-1;
			}
		}
		max_arr.push_back(arr2[ans]-arr1[i]);
	}
	for(auto x:max_arr) cout << x << " ";
	cout << endl;
}