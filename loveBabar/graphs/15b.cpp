// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    bool isValid(vector<vector<char>> M, bool** visited, int row, int col, int ROW, int COL){
        // if(r<0 or c<0 or r>=n or c>=m) return false;
        // if(visited[r][c] or (M[r][c]=='0')) return false;
        // return true;
        return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && ((M[row][col]=='1') && !visited[row][col]);
    }
    void dfs(vector<vector<char>> M, bool** visited, int r, int c, int n, int m){
        int dRow[8] = {-1,-1,-1,0,1,1,1,0};
        int dCol[8] = {-1,0,1,1,1,0,-1,-1};
        visited[r][c]=true;
        for (int i = 0; i < 8; ++i)
        {
            int adjx=r+dRow[i], adjy=c+dCol[i];
            if(isValid(M,visited,adjx,adjy,n,m)) dfs(M,visited,adjx,adjy,n,m);
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        bool** visited = new bool*[n];
        for (int i = 0; i < n; ++i)
        {
            visited[i] = new bool[m];
            for (int j = 0; j < m; ++j)
            {
                visited[i][j]=false;
            
            }
        }

        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if(!visited[i][j] and grid[i][j]=='1'){
                    res++;
                    dfs(grid,visited,i,j,n,m);
                }
            }
        }
        return res;
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