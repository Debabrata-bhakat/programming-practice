// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
// https://www.youtube.com/watch?v=UvksR0hR9nA

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        int dp[205][205];
        memset(dp,-1,sizeof(dp));
        for (int i = 0; i <= n; ++i)
        {
        	for (int j = 0; j <= k; ++j)
        	{
        		if(i==0) continue;
        		if(j==0) {dp[i][j]=0;continue;}
        		if(j==1) {dp[i][j]=1;continue;}
        		if(i==1) {dp[i][j]=j;continue;}
        		int res = INT_MAX;
        		for (int f = 1; f <= j; ++f)
        		{
        			int x = dp[i-1][f-1]; // break
        			int y = dp[i][j-f]; // does not break
        			res = min(max(x,y),res);
        		}
        		dp[i][j]=res+1;
        	}
        }
        return dp[n][k];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends