// https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1
// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
	int mod = 1e9+7;
	int helper(int n){
		// base case
		if(n==1 or n==0) return 1;
		// recursion
		int smallOutput1 = helper(n-1), smallOutput2 = helper(n-2);
		int res = smallOutput1;
		for (int i = 0; i < n-1; ++i)
		{
			res = (res + smallOutput2)%mod;
		}		
		return res;
	}
	int helper_mem(int n, int* output){
		// base case
		if(n==1 or n==0) return 1;
		// check ans
		if(output[n]!=-1) return output[n];
		// recursion
		int smallOutput1 = helper_mem(n-1,output), smallOutput2 = helper_mem(n-2,output);
		int res = (smallOutput1 + ((long long int )1*(n-1) * (long long int )1*smallOutput2)%mod)%mod;
		// for (int i = 0; i < n-1; ++i)
		// {
		// 	res = (res + smallOutput2)%mod;
		// }
		output[n] = res;
		return res;
	}
    int countFriendsPairings(int n) 
    { 
        // code here
        int* output = new int[n+1];
        for (int i = 0; i < n+1; ++i)
        {
        	output[i]=-1;
        }
    	return helper_mem(n,output);
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends