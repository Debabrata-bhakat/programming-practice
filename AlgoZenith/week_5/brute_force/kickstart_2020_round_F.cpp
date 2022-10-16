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
int s,ra,pa,rb,pb,c;
int allowed[10][10];

inline bool check(){
	if(x>=1 and y>=1 and x<=s and y<=2*x-1 and allowed[x][y]==0) return 1;
	else return 0;
}

int getBest(int a, int b, int x, int y){
	vector<pair<int,int>> move1, move2;
	if(check(a,b-1)){
		move1.emplace_back(make_pair(a,b-1));
	}
	if(check(a,b+1)){
		move1.emplace_back(make_pair(a,b+1));
	}
}

void solve(){
	cin>>s>>ra>>pa>>rb>>pb>>c;
	memset(allowed,0,sizeof(allowed));
	allowed[ra][pa]=1;
	allowed[rb][pb]=1;
	for(int i=0;i<c;i++){
		int x,y;
		cin>>x>>y;
		allowed[x][y]=1;
	}
	cout << getBest(ra,pa,rb,pb) << endl;
}