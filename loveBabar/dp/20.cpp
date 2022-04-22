// https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        // code here
        int dp[1005];
        dp[0]=1;
        for (int i = 1; i < N; ++i)
        {
        	int curr = A[i];
        	dp[i]=1;
        	for (int j = 0; j < i; ++j)
        	{
        		if(abs(A[i]-A[j])==1) dp[i] = max(dp[i],dp[j]+1);
        	}
        }
        // find max
        int res = INT_MIN;
        for (int i = 0; i < N; ++i)
        {
        	res = max(res,dp[i]);
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends