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
    // cin >> t;
    t=1;
    while(t--) solve();
}
int n;
vector<int> placed;
int ans=0;

void rec(int row){
	if(row==n){
		ans++; return;
	}
	for(int col=0;col<n;col++){
		bool safe=1;
		for(int pRow=0;pRow<row;pRow++){
			int pCol = placed[pRow];
			if(pCol==col or (abs(row-pRow)==abs(col-pCol))){
				safe=0;
			}
		}
		if(safe){
			placed.push_back(col);
			rec(row+1);
			placed.pop_back();
		}
	}
}

void solve(){
	cin>>n;	
	rec(0);
	cout << ans << endl;
}