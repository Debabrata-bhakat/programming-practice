// https://practice.geeksforgeeks.org/problems/ncr1019/1

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
	long long int mod = 1e9 + 7;
	int helper_mem(int n, int r, int** output){
		// base case
        if(n==r or r==0) return 1;
        if(n<r) return 0;
        // check ans
        if(output[n][r]!=-1) return output[n][r];
        int smallOutput1 = helper_mem(n-1,r-1,output),smallOutput2=helper_mem(n-1,r,output);
        output[n][r] = (smallOutput1+smallOutput2)%mod; 
        return output[n][r];
	}
	int helper_dp(int n, int r, int** output){
		// fill first colomn
		for (int i = 0; i < n+1; ++i)
		{
			output[i][0] = 1;
		}
		// fill diagnoal
		for (int i = 0; i < min(n,r)+1; ++i)
		{
			output[i][i]=1;
		}
		// fill n<r
		for (int i = 0; i < n+1; ++i)
		{
			for (int j = 0; j < r+1; ++j)
			{
				if(j>i) output[i][j] = 0;
			}
		}
		// fill remaining
		for (int i = 0; i < n+1; ++i)
		{
			for (int j = 0; j < r+1; ++j)
			{
				if(output[i][j]!=-1) continue;
				output[i][j] = (output[i-1][j-1] + output[i-1][j])%mod;
			}
		}
		return output[n][r];
	}
    int nCr(int n, int r){
        // base case
        // if(n==r or r==0) return 1;
        // int smallOutput1 = nCr(n-1,r-1), smallOutput2 = nCr(n-1,r);
        // return (smallOutput1+smallOutput2)%mod;
        int** output = new int*[n+1];
        for (int i = 0; i < n+1; ++i)
        {
            output[i] = new int[r+1];
            for (int j = 0; j < r+1; ++j)
            {
                output[i][j]=-1;
            
            }
        }
        // return helper_mem(n,r,output);
        return helper_dp(n,r,output);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends