// https://www.codechef.com/submit/MAKEABEQUAL
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
	lli n;cin>>n;
	vector<lli> arra(n), arrb(n);
	lli sum1=0,sum2=0;
	for(lli i=0;i<n;i++) {cin>>arra[i];sum1+=arra[i];}
	for(lli i=0;i<n;i++) {cin>>arrb[i];sum2+=arrb[i];}
	if(sum1!=sum2){cout <<"-1\n"; return;}
	lli res=0;
	for(lli i=0;i<n;i++){
		res+=abs(arra[i]-arrb[i]);
	}
	cout << res/2 << endl;

}