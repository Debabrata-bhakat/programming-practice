// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1/
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int si, int ei, int arr[]){
        // base case
        if(si+1==ei) return 0;
        // recursive calls
        int res = INT_MAX;
        for (int i = si+1; i < ei; ++i)
        {
            int smallOutput1 = helper(si,i,arr);
            int smallOutput2 = helper(i,ei,arr);
            int smallOutput3 = smallOutput1 + smallOutput2 + arr[si]*arr[ei]*arr[i];
            if(smallOutput3<res) res = smallOutput3;
        }
        return res;
    }
    int helper_mem(int si, int ei, int arr[], int** output){
        // base case
        if(si+1==ei) return 0;
        // check ans
        if(output[si][ei]!=-1) return output[si][ei];
        // recursion
        int res = INT_MAX;
        for (int i = si+1; i < ei; ++i)
        {
            int smallOutput1 = helper_mem(si,i,arr,output);
            int smallOutput2 = helper_mem(i,ei,arr,output);
            int smallOutput3 = smallOutput1 + smallOutput2 + arr[si]*arr[ei]*arr[i];
            if(smallOutput3<res) res = smallOutput3;
        }
        output[si][ei] = res;
        return res;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int** output = new int*[N];
        for (int i = 0; i < N; ++i)
        {
            output[i] = new int[N];
            for (int j = 0; j < N; ++j)
            {
                output[i][j]=-1;
            
            }
        }
        return helper_mem(0,N-1,arr,output);
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends