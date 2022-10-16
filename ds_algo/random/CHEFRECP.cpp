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
	map<int,int> freq;
	map<int,int> seen;
	int prev = arr[0],cnt=1; seen[arr[0]]=1;
	for(int i=1;i<n;i++){
		if(arr[i] == prev){
			cnt++;continue;
		}else{
			if(freq[cnt]==1 or seen[arr[i]]==1){
				cout << "NO\n"; return;
			}
			freq[cnt]=1; seen[prev]=1; prev=arr[i];cnt=1; 
		}
	}	
	if(freq[cnt]==1) cout << "NO\n";
	else cout << "YES\n";
}