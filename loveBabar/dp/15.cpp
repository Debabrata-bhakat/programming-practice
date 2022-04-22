// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
    	vector<int> dp(n+1,INT_MAX);dp[0] = INT_MIN;
    	for (int i = 0; i < n; ++i)
    	{
    		auto it = upper_bound(dp.begin(),dp.end(),a[i]);
    		int idx = it-dp.begin();
    		if(a[i]>dp[idx-1] and a[i]<dp[idx]) dp[idx] = a[i];
    	}
    	// find first non INT_MAX
    	for (int i = n; i > 0 ; --i)
    	{
    		if(dp[i]!=INT_MAX) return i;
    	}
    	return 0;
    }
    // int longestSubsequence(int n, int a[])
    // {
    //    // your code here
    // 	int* res = new int[n];
    // 	res[0]=1;
    // 	for (int i = 1; i < n; ++i)
    // 	{
    // 		int curr_max=0;
    // 		for (int j = 0; j < i; ++j)
    // 		{
    // 			if(curr_max<res[j] and a[i]>a[j]) curr_max=res[j];
    // 		}
    // 		res[i]=curr_max+1;
    // 	}
    // 	int ans=res[0];
    // 	for (int i = 0; i < n; ++i)
    // 	{
    // 		if(ans<res[i]) ans=res[i];
    // 	}
    // 	return ans;
    // }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends