// https://practice.geeksforgeeks.org/problems/edit-distance3702/1
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  	int helper(string s, string t){
  		// base
  		if(s==t) return 0;
  		if(s.size()==0) return t.size();
  		if(t.size()==0) return s.size();
  		// first char same
  		if(s[0]==t[0]) return helper(s.substr(1),t.substr(1));
  		// replace
  		int smallOutput1 = helper(s.substr(1),t.substr(1));
  		// add
  		int smallOutput2 = helper(s,t.substr(1));
  		// remove
  		int smallOutput3 = helper(s.substr(1),t);
  		return min(smallOutput1,min(smallOutput2,smallOutput3)) + 1;
  	}
  	int helper_mem(string s, string t, int** output){
  		// base
  		if(s==t)return 0;
  		if(s.size()==0) return t.size();
  		if(t.size()==0) return s.size();
  		// check ans
  		int n = s.size(),m = t.size();
  		if(output[n][m]!=-1) return output[n][m];
  		if(s[0]==t[0]) return helper_mem(s.substr(1),t.substr(1),output);
  		// replace
  		int smallOutput1 = helper_mem(s.substr(1),t.substr(1),output);
  		// add
  		int smallOutput2 = helper_mem(s,t.substr(1),output);
  		// remove
  		int smallOutput3 = helper_mem(s.substr(1),t,output);
  		output[n][m] = min(smallOutput1,min(smallOutput2,smallOutput3)) + 1;
  		return output[n][m];
  	}
  	int helper_dp(string s, string t, int** output){
  		// fill the first row and column
  		int n = s.size(), m = t.size();
  		for (int i = 0; i < n+1; ++i)
  		{
  			output[i][0] = i;
  		}
  		for (int i = 0; i < m+1; ++i)
  		{
  			output[0][i] = i;
  		}
  		for (int i = 0; i < n+1; ++i)
  		{
  			for (int j = 0; j < m+1; ++j)
  			{
  				if(output[i][j]!=-1) continue;
  				char c1 = s[n-i], c2 = t[m-j];
  				if(c1==c2){
  					output[i][j] = output[i-1][j-1];
  					continue;
  				}
  				output[i][j] = min(output[i-1][j-1],min(output[i-1][j],output[i][j-1])) + 1;
  			}
  		}
  		return output[n][m];
  	}
    int editDistance(string s, string t) {
        // Code here
        int n = s.size()+1, m = t.size()+1;
        int** output = new int*[n];
        for (int i = 0; i < n; ++i)
        {
            output[i] = new int[m];
            for (int j = 0; j < m; ++j)
            {
                output[i][j]=-1;
            
            }
        }
        return helper_dp(s,t,output);
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends