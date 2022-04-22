// https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)	
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends
int dp[30][30][30];
int helper(string a, string b, string c, int i, int j, int k){
	if(i==0 or j==0 or k==0) return 0;
	if(a[i-1]==b[j-1] and b[j-1]==c[k-1]) return 1+helper(a,b,c,i-1,j-1,k-1);
	else return max(helper(a,b,c,i-1,j,k),max(helper(a,b,c,i,j-1,k),helper(a,b,c,i,j,k-1)));
}
int helper_mem(string a, string b, string c, int i, int j, int k){
	if(i==0 or j==0 or k==0) return 0;
	if(dp[i][j][k]!=-1) return dp[i][j][k];
	int ans;
	if(a[i-1]==b[j-1] and b[j-1]==c[k-1]) ans = 1+helper_mem(a,b,c,i-1,j-1,k-1);
	else ans = max(helper_mem(a,b,c,i-1,j,k),max(helper_mem(a,b,c,i,j-1,k),helper_mem(a,b,c,i,j,k-1)));	
	dp[i][j][k] = ans;
	return ans;
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
	memset(dp,-1,sizeof(dp));
    return helper_mem(A,B,C,A.size(),B.size(),C.size());

}

/*
1
5 8 13
geeks geeksfor geeksforgeeks
*/