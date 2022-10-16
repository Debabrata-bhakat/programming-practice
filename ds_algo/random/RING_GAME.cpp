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
	int n;cin>>n; vector<int> arr(n); for(int i=0;i<n;i++) cin>>arr[i];
	int c0=0,c1=0,diff=0;;
	for(int i=0;i<n;i++){
		if(arr[i]==0) c0++; else c1++;
		if(arr[i]!=arr[(i+1)%n]) diff++; 
	}	
	int diff_ans = min(c0,c1)*2;
	int moves = (diff_ans - diff)/2;
	if(moves%2==0) cout << "bob\n";
	else cout << "alice\n";
}