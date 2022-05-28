// https://codeforces.com/contest/1676/problem/D
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

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    cin >> t;
    // t=1;
    while(t--) solve();
}

int helper(vector<vector<int>>arr, int i, int j){
	int n = arr.size(),m=arr[0].size(),res=arr[i][j];
	// top left
	int tempi = i-1, tempj=j-1;
	while(tempi>=0 and tempj>=0){
		res += arr[tempi--][tempj--];
	}
	// top right
	tempi=i-1, tempj=j+1;
	while(tempi>=0 and tempj<m){
		res += arr[tempi--][tempj++];
	}
	// bottom left
	tempi=i+1, tempj=j-1;
	while(tempi<n and tempj>=0){
		res += arr[tempi++][tempj--];
	}
	// bottom right
	tempi=i+1, tempj=j+1;
	while(tempi<n and tempj<m){
		res += arr[tempi++][tempj++];
	}
	return res;
}

void solve(){
	int n,m;cin>>n>>m;
	vector<vector<int>> arr;
	for (int i = 0; i < n; ++i)
	{
		vector<int> temp_v;
		for (int j = 0; j < m; ++j)
		{
			int temp; cin>>temp;
			temp_v.push_back(temp);
		}
		arr.push_back(temp_v);
	}
	int ans=-1e9;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			ans = max(ans,helper(arr,i,j));
		}
	}
	cout << ans << endl;
}