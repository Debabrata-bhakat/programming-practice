#include <bits/stdc++.h>
#define ull unsigned long long 
#define ll long long
using namespace std;

class prob
{
public:
	int s, t, d;
	Score(int s, int t, int d){
		this->s = s;
		this->t = t;
		this->d = d;
	};
	
};

bool cmp(prob a, prob b){
	return 1LL*a.t*b.d < 1LL*b.t*a.d;
}

void solve(){
	int n;cin>>n;
	for (int i = 0; i < n; ++i)
	{
		int a,b,c; cin>>a>>b>>c;
		prob temp(a,b,c);
		v.push_back(temp);
	}
	vector<prob> v;
	sort(v.begin(),v.end(),cmp);
	for(auto x:v){
		cout << x.s << " " << x.t << " " x.d << '\n';
	}
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