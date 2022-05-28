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

void solve(){
	int n;cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(n==1){
		cout << "1\n"; return;
	}
	sort(arr.begin(),arr.end());
	int a_prev=arr[0], b_prev=arr[1], a_cnt=1, b_cnt=1,curr=0;
	for(int i=2;i<n;i++){
		if(curr==0){
			if(arr[i]==a_prev) continue;
			a_prev = arr[i]; a_cnt++; curr=1;
		}else{
			if(arr[i]==b_prev) continue;
			b_prev = arr[i]; b_cnt++; curr=0;
		}
	}
	if(a_cnt>b_cnt and a_prev!=b_prev) b_cnt++;
	cout << min(a_cnt,b_cnt) << endl;
}