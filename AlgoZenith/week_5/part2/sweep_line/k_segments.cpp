##include <bits/stdc++.h>
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
	lli n;
	cin>>n;
	vector<pair<int,int>> event;
	for (int i = 0; i < n; ++i)
	{
		lli r,n; cin>>l>>r;
		event.push_back({l,-1}); event.push_back({r,1});
	}
	sort(event.begin(),event.end());
	int cnt=0;
	lli lenCovered[n+1];
	memset(lenCovered,0,sizeof(lenCovered));

	for(int i=0;i<event.size();i++){
		int j=i;
		// Design what you do in the event
		while(j<event.size() && event[j].first==event[i].first){
			cnt+=event[j].second;
			j++;
		}
		i=j-1;
		// Add events contribution
		if(i!=(event.size()-1)){
			lli segLen = event[i+1].first - event[i].first;
			lenCovered[cnt]+=segLen;
		}
	}

	for(int i=n-1;i>=1;i--){
		lenCovered[i]+=lenCovered[i+1];
	}
}