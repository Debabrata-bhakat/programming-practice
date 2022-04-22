// https://practice.geeksforgeeks.org/problems/coin-change2448/1
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int helper(int* S, int m, int n){
        // base case
        if(n<0) return 0;
        if(m==0 and n==0) return 1;

        // recursive calls
        long long int smallOutput1 = helper(S,m,n-S[0]);
        long long int smallOutput2 = helper(S+1,m-1,n);
        return smallOutput1+smallOutput2;
    }
    long long int helper_mem(int** output, int m, int n, int S[], int M){
        // base case
        if(n==0) return 1;
        if(n<0 or (m==M and n!=0)) return 0;
        // check if answer already exits
        if(output[n][m]!=-1) return output[n][m];
        // recursive calls
        long long int smallOutput1 = helper_mem(output,m,n-S[m],S,M);
        long long int smallOutput2 = helper_mem(output,m+1,n,S,M);
        output[n][m] = smallOutput1+smallOutput2; 
        return smallOutput1+smallOutput2;

    }
    long long int count(int S[], int m, int n) {

        // code here.
        int** output = new int*[n+1];
        for (int i = 0; i < n+1; ++i)
        {
            output[i] = new int[m];
            for (int j = 0; j < m; ++j)
            {
                output[i][j]=-1;
            
            }
        }
        return helper_mem(output,0,n,S,m);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends