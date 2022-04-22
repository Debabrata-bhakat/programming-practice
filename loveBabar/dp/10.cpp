// https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
	int dRow[3] = {-1,1,0};
	int dCol[3] = {1,1,1};
	bool isValid(int r, int c, int n, int m){
		if(r<0 or c<0 or r>=n or c>=m) return false;
		return true;
	}
	int helper(int n, int m, vector<vector<int>>M){
		int ROW = M.size(), COL = M[0].size();
		// base case
		if(m==COL-1) return M[n][m];
		// recursion
		int res = INT_MIN;
		for (int i = 0; i < 3; ++i)
		{
			int adjr = n + dRow[i], adjc = m + dCol[i];
			if(!isValid(adjr,adjc,ROW,COL)) continue;
			int smallOutput = helper(adjr,adjc,M);
			if(smallOutput>res) res = smallOutput;
		}
		return res + M[n][m];

	}
	int helper_mem(int n, int m, vector<vector<int>>M, int** output){
		int ROW = M.size(),COL = M[0].size();
		// base case
		if(m==COL-1) return M[n][m];
		// check ans
		if(output[n][m]!=-1) return output[n][m];
		// recursion
		int res = INT_MIN;
		for (int i = 0; i < 3; ++i)
		{
			int adjr = n + dRow[i], adjc = m + dCol[i];
			if(!isValid(adjr,adjc,ROW,COL)) continue;
			int smallOutput = helper_mem(adjr,adjc,M,output);
			if(smallOutput>res) res	= smallOutput;
		}
		output[n][m] = res + M[n][m];
		return output[n][m];
	}
	int helper_dp(vector<vector<int>>M){
		int ROW=M.size(),COL=M[0].size();
		int** output = new int*[ROW];
        for (int i = 0; i < ROW; ++i)
        {
            output[i] = new int[COL];
            for (int j = 0; j < COL; ++j)
            {
                output[i][j]=-1;
            
            }
        }
        // fill the last column
        for (int i = 0; i < ROW; ++i)
        {
        	output[i][COL-1] = M[i][COL-1];
        }
        // fill the remaining cells
        for (int i = COL-2; i >= 0 ; --i)
        {
        	for (int j = 0; j < ROW; ++j)
        	{
        		int res = INT_MIN;
        		for (int k = 0; k < 3; ++k)
        		{
        			int adjr = j + dRow[k], adjc = i + dCol[k];
        			if(!isValid(adjr,adjc,ROW,COL)) continue;
        			if(res<output[adjr][adjc]) res = output[adjr][adjc];
        		}
        		output[j][i] = res + M[j][i];
        	}
        }
        // find the max in first col
        int res = INT_MIN;
        for (int i = 0; i < ROW; ++i)
        {
        	if(res<output[i][0]) res = output[i][0];
        }
        return res;
	}
	int helper(vector<vector<int>>M){
		int ROW=M.size(),COL=M[0].size();
		int** output = new int*[ROW];
        for (int i = 0; i < ROW; ++i)
        {
            output[i] = new int[COL];
            for (int j = 0; j < COL; ++j)
            {
                output[i][j]=-1;
            
            }
        }
		int res = INT_MIN;
		
		for (int i = 0; i < ROW; ++i)
		{
			int smallOutput = helper_mem(i,0,M,output);
			if(smallOutput>res) res = smallOutput;
		}
		return res;
	}
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
    	return helper_dp(M);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends