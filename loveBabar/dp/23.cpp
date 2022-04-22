// https://practice.geeksforgeeks.org/problems/max-length-chain/1
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
bool sortBySecond(struct val a, struct val b){
	return a.second < b.second;
}
int maxChainLen(struct val p[],int n)
{
//Your code here
	int dp[100];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	sort(p,p+n,sortBySecond);
	for (int i = 1; i < n; ++i)
	{
		int curr = p[i].first;
		for (int j = 0; j < i; ++j)
		{
			if(p[j].second<curr) dp[i] = max(dp[i],dp[j]+1);
		}
	}
	// find max
	int res=INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		res = max(res,dp[i]);
	}
	return res;
}