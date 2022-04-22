// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int helper2_dp(string s1, string s2, int** output){
	        // fill default
	        int x = s1.size()+1, y=s2.size()+1;
	        for (int i = 0; i < x; ++i)
	        {
	            output[i][s2.size()] = 0;
	        }
	        for (int i = 0; i < y; ++i)
	        {
	            output[s1.size()][i] = 0;
	        }
	        // fill remaining
	        for (int i = s1.size()-1; i >=0 ; --i)
	        {
	            for (int j = s2.size()-1; j >=0 ; --j)
	            {
	                if(s1[i]==s2[j] and i!=j) {
	                    output[i][j] = output[i+1][j+1]+1;
	                    continue;
	                }
	                output[i][j] = max(output[i+1][j+1],max(output[i][j+1],output[i+1][j]));
	            }
	        }
	        return output[0][0];
	    }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int ROW=str.size()+1,COL=str.size()+1;
	        int** output = new int*[ROW];
	        for (int i = 0; i < ROW; ++i)
	        {
	            output[i] = new int[COL];
	            for (int j = 0; j < COL; ++j)
	            {
	                output[i][j]=-1;
	            
	            }
	        }
		    return helper2_dp(str,str,output);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends


