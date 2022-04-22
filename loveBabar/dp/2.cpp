// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int helper(int W, int wt[], int val[], int n){
    	// base case
    	if(W==0 or n==0) return 0;
    	int smallOutput1;
    	if(W-wt[0] < 0) smallOutput1=-1;
    	else smallOutput1 = helper(W-wt[0],wt+1,val+1,n-1) + val[0];
    	int smallOutput2 = helper(W,wt+1,val+1,n-1);
    	return max(smallOutput1,smallOutput2);
    }
    int helper_mem(int W, int n, int wt[], int val[], int** output){
    	// base case
    	if(W==0 or n==0) return 0;
    	// check if already exists
    	if(output[W][n]!=-1) return output[W][n];
    	// recursion
    	int smallOutput1;
    	if(W-wt[0]<0) smallOutput1=-1;
    	else smallOutput1 = helper_mem(W-wt[0],n-1,wt+1,val+1,output)+val[0];
    	int smallOutput2 = helper_mem(W,n-1,wt+1,val+1,output);
    	int res = max(smallOutput1,smallOutput2);
    	output[W][n] = res;
    	return res;
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    	int** output = new int*[W+1];
        for (int i = 0; i < W+1; ++i)
        {
            output[i] = new int[n+1];
            for (int j = 0; j < n+1; ++j)
            {
                output[i][j]=-1;
            
            }
        }
    	return helper_mem(W,n,wt,val,output);
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends

/*
1
3 4
1 2 3
4  5 1
*/