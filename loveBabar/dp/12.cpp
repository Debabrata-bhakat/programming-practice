// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
	int helper(int n, int* a){
		// base case
		if(n<0) return -1;
		if(n==0) return 0;
		// recursion
		int ans = -1;
		for (int i = 0; i < 3; ++i)
		{
			int smallOutput = helper(n-a[i],a);
			if(smallOutput>ans) ans = smallOutput;
		}
		if(ans==-1) return -1;
		return ans+1;
	}
    int helper_mem(int n, int* a, int* output){
        // base case
        if(n<0) return -1;
        if(n==0) return 0;
        // check ans
        if(output[n]!=-1) return output[n];
        // recursion
        int ans = -1;
        for (int i = 0; i < 3; ++i)
        {
            int smallOutput = helper_mem(n-a[i],a,output);
            if(smallOutput>ans) ans = smallOutput;
        }
        if(ans==-1) output[n]=-1;
        else output[n] = ans+1;
        return output[n];
    }
    int helper_dp(int n, int* a, int* output){
        // fill default
        output[0] = 0;
        for (int i = 1; i < n+1; ++i)
        {
            int ans=-1;
            for (int j = 0; j < 3; ++j)
            {
                // cout << " i " << i << " j " << j << endl;
                int prev = i-a[j];
                int smallOutput;
                if(prev<0) smallOutput = -1;
                else smallOutput = output[i-a[j]];
                if(smallOutput>ans) ans=smallOutput;
            }
            if(ans==-1) output[i]=-1;
            else output[i]=ans+1;
        }
        if(output[n]==-1) return 0;
        return output[n];
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int a[3] = {x,y,z};
        int* output = new int[n+1];
        for (int i = 0; i < n+1; ++i)
        {
            output[i] = 0;
        }
        return helper_dp(n,a,output);
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends