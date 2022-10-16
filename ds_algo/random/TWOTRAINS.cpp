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

void solve(){
	int n;cin>>n;n--;
	vector<int> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	int max_i = arr[0],sum=0;
	for(int i=0;i<n;i++) {max_i =max(max_i,arr[i]);sum+=arr[i];}
	cout << max_i+sum << endl;
}

void solve2(){
	int n;cin>>n;
	vector<int>arr(n+1);
	arr[0]=0; arr[1]=0;
	for(int i=2;i<n+1;i++){
		cin>>arr[i];
	}	
	vector<int> pre(n+1);
	pre[0]=arr[0];
	for(int i=1;i<n+1;i++){
		pre[i] = pre[i-1]+arr[i];
	}
	int t1=2, t2=1;
	int time=arr[2];
	// for(auto x: pre)cout << x << endl;
	// cout << endl;
	while(t2<n){
		if(t2<t1){
			time+=arr[t2+1];t2++;
			t1 = upper_bound(pre.begin(),pre.end(),time) - pre.begin(); t1--;
		}else{
			t1 = lower_bound(pre.begin(),pre.end(),time) - pre.begin(); 
			time = pre[t1];
		}
	}
	cout << time << endl;
}