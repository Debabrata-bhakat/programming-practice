#include <bits/stdc++.h>
#define ull unsigned long long 
#define ll long long
using namespace std;

void solve(){
	int n;cin>>n;
	int cnt[31];
	memset(cnt,0,sizeof(cnt));
	for (int i = 0; i < n; ++i)
	{
		int x; cin>>x;
		for (int j = 0; j < 31; ++j)
		{
			if( (x>>j) &1){
				cnt[j]++;
			}
		}
	}
	long long ans = 0;
	for (int j = 0; j < 31; ++j)
	{
		long long temp = 1LL * cnt[j] * (n-cnt[j]);
		ans += temp*(1LL<<j);
	}
	cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;cin>>t;
    while(t--) solve();
}