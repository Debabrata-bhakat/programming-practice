// https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1/#
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> a, int n){
	vector<int> dp(n+1,-1);
	dp[0]=0;
	dp[1]=a[1];
	dp[2]=a[2]+a[1];
	for (int i = 3; i < n+1; ++i)
	{
		int x = dp[i-1];
		int y = a[i] + dp[i-2];
		int z = a[i] + a[i-1] + dp[i-3];
		dp[i] = max(x,max(y,z));
	}
	return max(dp[n],max(dp[n-1],dp[n-2]));
}

int main(){
	int n;cin>>n;
	vector<int> a(n+1);
	for (int i = 1; i < n+1; ++i)
	{
		cin>>a[i];
	}
	cout << solve(a,n) << endl;
}