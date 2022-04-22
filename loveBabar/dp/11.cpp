// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int mod = 1e9+7;
    long long helper(int n, int k, long long** output){
    	output[2][1] = k;
    	output[0][2] = k;
    	output[1][2] = (k*(k-1))%mod;
    	output[2][2] = (output[0][2] + output[1][2])%mod;
    	for (int i = 3; i < n+1; ++i)
    	{
    		output[0][i] = output[1][i-1];
    		output[1][i] = (output[2][i-1] * (k-1))%mod;
    		output[2][i] = (output[0][i] + output[1][i])%mod;
    	}
    	return output[2][n];
    }
    long long countWays(int n, int k){
        // code here
        int ROW=3,COL=n+1;
    	long long** output = new long long*[ROW];
        for (int i = 0; i < ROW; ++i)
        {
            output[i] = new long long[COL];
            for (int j = 0; j < COL; ++j)
            {
                output[i][j]=-1;
            
            }
        }
        return helper(n,k,output);
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends