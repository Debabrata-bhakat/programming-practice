#include <bits/stdc++.h>
#define ull unsigned long long 
using lli = long long int;
using namespace std;
int mod = 1e9+7;
#define F first 
#define S second 
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
	lli n; cin>>n;
	vector<pair<lli,pair<lli,lli>>> event;
	for(int i=0;i<n;i++){
		lli r,l,x;cin>>l>>r>>x;
		event.push_back({l,{1,x}});
		event.push_back({r,{3,x}});
	}	
	lli q;cin>>q;
	lli ansQuery[q];
	for(int i=0;i<q;i++){
		lli y; cin>>y;
		event.push_back({y,{2,i}});
	}
	sort(event.begin(),event.end());

	multiset<lli> mt;

	for(int i=0;i<event.size();i++){
		if(event[i].S.F==1) {
			mt.insert(event[i].S.S);
		}else if{
			if(mt.empty()){
				ansQuery[event[i].S.S]=1;
			}else{
				ansQuery[event[i].S.S] = *mt.rbegin();
			}
		}else{
			mt.erase(mt.find(event[i].S.S));
		}
	}

	for(int i=0;i<q;i++){
		cout << ansQuery[i] << endl;
	}
}