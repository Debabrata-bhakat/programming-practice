// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int cx[8]={0,0,1,1,1,-1,-1,-1};
    int cy[8]={1,-1,-1,0,1,-1,0,1};
    bool isvalid(int i,int j,int m,int n)
    {
        if(i>=m || j>=n || i<0 || j<0)
        return false;
        else
        return true;
    }
    void dfs(int i,int j,vector<vector<char>>& grid,int m,int n)
    {
        if(grid[i][j]=='1')
        {
        grid[i][j]='2';
    
    
        for(int k=0;k<8;k++)
        {
            int X=i+cx[k];
            int Y=j+cy[k];
            if(isvalid(X,Y,m,n) )
            dfs(X,Y,grid,m,n);
        }
        

        
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {   
                    dfs(i,j,grid,m,n);
                    ans++;
                }
                
                
            }
        }
        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends