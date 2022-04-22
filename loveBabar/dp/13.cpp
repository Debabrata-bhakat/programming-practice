// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
	int helper_mem(string s1, string s2, int** output){
		// base case
		if(s1.size()==0 or s2.size()==0) return 0;
		if(s1==s2) return s1.size();
		// check ans
		if(output[s1.size()][s2.size()]!=-1) return output[s1.size()][s2.size()];
		// recursion
		// if first char same
		if(s1[0]==s2[0]) return helper_mem(s1.substr(1),s2.substr(1),output)+1;
		// take first char of first string
		int in=-1;
		for (int i = 0; i < s2.size(); ++i)
		{
			if(s2[i]==s1[0]){
				in=i;
				break;
			}
		}
		int smallOutput1;
		if(in==-1) smallOutput1=0;
		else smallOutput1 = helper_mem(s1.substr(1),s2.substr(in+1),output)+1;
		// take first char of second string
    	in=-1;
    	for (int i = 0; i < s1.size(); ++i)
    	{
    		if(s1[i]==s2[0]){
    			in=i;
    			break;
    		}
    	}
    	int smallOutput2;
    	if(in==-1) smallOutput2 = 0;
    	else smallOutput2 = helper_mem(s1.substr(in+1),s2.substr(1),output)+1;
    	// dont take any
    	int smallOutput3 = helper_mem(s1.substr(1),s2.substr(1),output);
    	output[s1.size()][s2.size()] = max(smallOutput1,max(smallOutput2,smallOutput3));
    	return output[s1.size()][s2.size()];

	}
    int helper(string s1, string s2){
    	// base case
    	if(s1.size()==0 or s2.size()==0) return 0;
    	if(s1==s2) return s1.size();
    	// recursive calls
    	// if first char same
    	if(s1[0]==s2[0]) return helper(s1.substr(1),s2.substr(1))+1;
    	// take first char of first string
    	int in=-1;
    	for (int i = 0; i < s2.size(); ++i)
    	{
    		if(s2[i]==s1[0]){
    			in=i;
    			break;
    		}
    	}
    	int smallOutput1;
    	if(in==-1) smallOutput1=0;
    	else smallOutput1 = helper(s1.substr(1),s2.substr(in+1))+1;
    	// take first char of second string
    	in=-1;
    	for (int i = 0; i < s1.size(); ++i)
    	{
    		if(s1[i]==s2[0]){
    			in=i;
    			break;
    		}
    	}
    	int smallOutput2;
    	if(in==-1) smallOutput2 = 0;
    	else smallOutput2 = helper(s1.substr(in+1),s2.substr(1))+1;
    	// dont take any
    	int smallOutput3 = helper(s1.substr(1),s2.substr(1));
    	return max(smallOutput1,max(smallOutput2,smallOutput3));
    }
    int helper2(string s1, string s2){
        // base case
        if(s1.size()==0 or s2.size()==0) return 0;
        // recursive calls
        // if first char same
        if(s1[0]==s2[0]) return helper2(s1.substr(1),s2.substr(1))+1;
        int smallOutput1 = helper2(s1.substr(1),s2.substr(1)), smallOutput2 = helper2(s1.substr(1),s2), smallOutput3 = helper(s1,s2.substr(1));
        return max(smallOutput1,max(smallOutput2,smallOutput3));
    }
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
                if(s1[i]==s2[j]) {
                    output[i][j] = output[i+1][j+1]+1;
                    continue;
                }
                output[i][j] = max(output[i+1][j+1],max(output[i][j+1],output[i+1][j]));
            }
        }
        return output[0][0];
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int ROW=x+1,COL=y+1;
        int** output = new int*[ROW];
        for (int i = 0; i < ROW; ++i)
        {
            output[i] = new int[COL];
            for (int j = 0; j < COL; ++j)
            {
                output[i][j]=-1;
            
            }
        }
    	// return helper_mem(s1,s2,output);
        return helper2_dp(s1,s2,output);
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends