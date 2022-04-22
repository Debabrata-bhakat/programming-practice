// https://practice.geeksforgeeks.org/problems/geek-and-his-binary-strings1951/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int mod = 1e9+7;
	int catalan(int n){
		if(n==0) return 1;
		int res = 0;
		for (int i = 0; i < n; ++i)
		{
			int temp = (catalan(i) * catalan(n-1-i))%mod;
			res += temp;
		}
		return res;
	}
	int catalan_mem(int n, int* output){
		// base case
		if(n==0) return 1;
		// check ans
		if(output[n]!=-1) return output[n];
		int res=0;
		for (int i = 0; i < n; ++i)
		{
			int temp = ((unsigned long long)1*catalan_mem(i,output) * (unsigned long long)1*catalan_mem(n-1-i,output))%mod;
			res = (res + temp)%mod;
		}
		output[n] = res;
		return res;
	}
	int prefixStrings(int N)
	{
	    // Your code goes here
	    int* output = new int[N+1];
	    for (int i = 0; i < N+1; ++i)
	    {
	    	output[i]=-1;
	    }
	    return catalan_mem(N,output);
	}

};
	

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n;
       	cin >> n;

       

        Solution ob;
        cout << ob.prefixStrings(n);
	    cout << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends