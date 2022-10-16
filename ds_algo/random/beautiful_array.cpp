// https://codeforces.com/contest/1715/problem/B
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
	lli n,k,b,s; cin>>n>>k>>b>>s;
	if(k*b>s){
		cout << "-1\n"; return;
	}	
	vector<lli> res;
	lli first = min(s,k*(b+1)-1);
	res.push_back(first);
	s-=first;
	// cout << s << endl;
	// cout << first << endl;
	if((k-1)*(n-1)<s){
		cout << "-1\n"; return;
	}
	while(s>0){
		lli temp = min(s,k-1);
		res.push_back(temp); s-=(temp);
	}
	while(res.size()<n){
		res.push_back(0);
	}
	for(auto x:res){
		cout << x << " ";
	}
	cout << endl;
}