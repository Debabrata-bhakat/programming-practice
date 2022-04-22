// https://www.youtube.com/watch?v=ww4V7vRIzSk&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=49
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> a){
	int dp[1005][1005];
	int n=a.size();
	memset(dp,-1,sizeof(dp));
	for (int i = n-1; i >= 0; --i)
	{
		for (int j = 0; j < n; ++j)
		{
			// base case
			if(i>j) continue;
			if(i==j) {dp[i][j]=a[i]; continue;}
			if(i+1==j) {dp[i][j]=max(a[i],a[j]); continue;}
			int x = min(dp[i+2][j],dp[i+1][j-1]) + a[i];
			int y = min(dp[i+1][j-1],dp[i][j-2]) + a[j];
			dp[i][j] = max(x,y);
		}
	}
	return dp[0][n-1];
}

int main(){
	int n;cin>>n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin>> a[i];
	}
	cout << solve(a) << endl;
}