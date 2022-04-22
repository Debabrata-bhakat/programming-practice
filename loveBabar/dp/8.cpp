// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1


// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
	int helper(int N, int arr[], int b1, int b2){
		// base case
		if(N==0 and b1==b2) return 1;
		if(N==0 and b1!=b2) return 0;
		// recursion
		int smallOutput1 = helper(N-1,arr+1,b1+arr[0],b2);
		int smallOutput2 = helper(N-1,arr+1,b1,b2+arr[0]);
		return smallOutput1 or smallOutput2;
	}
	int helper2(int N, int arr[], int sum){
		// base case
		if(N==0 and sum==0) return 1;
		if(N==0 and sum!=0) return 0;
		// recursion
		int smallOutput1 = helper2(N-1,arr+1,sum);
		int smallOutput2 = helper2(N-1,arr+1,sum-arr[0]);
		return smallOutput1 or smallOutput2;
	}
	int helper_mem(int N, int arr[], int sum, int** output){
		// base case
		if(N==0 and sum==0) return 1;
		if(N==0 and sum!=0) return 0;
		// check ans
		if(output[N][sum]!=-1) return output[N][sum];
		// recursion
		int smallOutput1 = helper_mem(N-1,arr+1,sum,output);
		int smallOutput2 = helper_mem(N-1,arr+1,sum-arr[0],output);
		output[N][sum] = smallOutput1 or smallOutput2;
		return output[N][sum];
	}
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for (int i = 0; i < N; ++i)
        {
        	sum+=arr[i];
        }
        if(sum%2==1) return 0;
        int** output = new int*[N+1];
        for (int i = 0; i < N+1; ++i)
        {
            output[i] = new int[sum];
            for (int j = 0; j < sum; ++j)
            {
                output[i][j]=-1;
            
            }
        }
    	return helper_mem(N,arr,sum/2,output);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends