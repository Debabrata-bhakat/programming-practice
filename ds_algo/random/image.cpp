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
	string s1,s2;cin>>s1>>s2;
	vector<int> arr(4); arr[0] = s1[0]; arr[1] = s1[1]; arr[2] = s2[0]; arr[3] = s2[1];
	sort(arr.begin(),arr.end());
	int c=0;
	for(int i=0;i<3;i++){
		if(arr[i]!=arr[i+1]) c++;
	}	
	if(c==0) cout << "0\n";
	else if(c==1) cout << "1\n";
	else if (c==2) cout << "2\n";
	else cout << "3\n";
}