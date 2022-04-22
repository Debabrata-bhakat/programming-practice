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
	int fact(int n){
		if(n==1) return 1;
		else return(n%mod * fact(n-1)%mod)%mod;
	}
    int nPr(int n, int r){
    	// base case
    	if(n<r) return 0;
    	if(n==r) return fact(n);
        if(r==0) return 1;
    	// recursion
    	int smallOutput1 = nPr(n-1,r);
    	int smallOutput2 = nPr(n-1,r-1);
    	int smallOutput3 = 0;
    	for (int i = 0; i < r; ++i)
    	{
    		smallOutput3 = (smallOutput3 + smallOutput2)%mod; 
    	}
    	return (smallOutput1+smallOutput3)%mod;
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
        cout<<ob.nPr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends