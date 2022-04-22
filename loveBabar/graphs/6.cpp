// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int dRow[4] = {-1,0,1,0};
    int dCol[4] = {0,1,0,-1};
    string dDir[4] = {"U","R","D","L"};
    bool** resVis(bool** visited, int n){
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                visited[i][j] = false;
            }
        }
        return visited;
    }
    bool isValid(int r, int c, int n, vector<vector<int>> &m, bool** visited){
        if(r<0 or c<0 or r>=n or c>=n or visited[r][c]) return false;
        if(!m[r][c]) return false;
        return true;
    }
    vector<string> helper(vector<vector<int>> &m, int n, int r, int c, bool** visited){
        // base case
        vector<string> ans;
        if(!m[r][c]) return ans;
        visited[r][c] = true;
        for (int i = 0; i < 4; ++i)
        {
            int adjx = r + dRow[i], adjy = c + dCol[i];
            if(!isValid(adjx, adjy, n, m, visited)) continue;
            if(adjx == n-1 and adjy == n-1){
                ans.push_back(dDir[i]);
                continue;
            }
            vector<string> smallOutput = helper(m,n,adjx, adjy, visited);
            for (int j = 0; j < smallOutput.size(); ++j)
            {
                smallOutput[j] = dDir[i] + smallOutput[j];
                ans.push_back(smallOutput[j]);
            }
            // ans.insert(ans.end(), smallOutput.begin(), smallOutput.end());
        }
        visited[r][c] = false;
        return ans;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        bool** visited = new bool*[n];
        for (int i = 0; i < n; ++i)
        {
            visited[i] = new bool[n];
        }
        vector<string> ans = helper(m, n, 0, 0, visited);
        // for (int i = 0; i < 4; ++i)
        // {
        //     resVis(visited, n);
        //     int adjx = dRow[i], adjy = dCol[i];
        //     if(!isValid(adjx, adjy, n, m, visited)) continue;
        //     vector<string> smallOutput = helper(m, n, adjx, adjy, visited);
        //     for (int j = 0; j < smallOutput.size(); ++j)
        //     {
        //         smallOutput[j] = dDir[i] + smallOutput[j];
        //     }
        //     ans.insert(ans.end(), smallOutput.begin(), smallOutput.end());
        // }
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends


/*
4
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1

4
0 1 1 1 
1 1 1 0 
1 0 1 1 
0 0 1 1
*/