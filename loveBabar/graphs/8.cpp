// https://leetcode.com/problems/flood-fill/


class Solution {
public:
    int dRow[4] = {-1,0,1,0};
    int dCol[4] = {0,1,0,-1};
    bool isValid(bool** visited, int m, int n, int r, int c, int startColor, vector<vector<int>> image){
        if(r<0 or c<0 or r>=m or c>=n or visited[r][c] or image[r][c]!=startColor) return false;
        return true;
    }
    vector<vector<int>> dfs(vector<vector<int>>&image, int sr, int sc, int newColor, bool** visited, int m, int n, int startColor){
        visited[sr][sc] = true;
        image[sr][sc] = newColor;
        for (int i = 0; i < 4; ++i)
        {
            int adjx = sr + dRow[i], adjy = sc + dCol[i];
            if(!isValid(visited, m, n, adjx, adjy, startColor, image)) continue;
            dfs(image, adjx, adjy, newColor, visited, m, n, startColor);
        }
        return image;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size();
        int startColor = image[sr][sc];
        bool** visited = new bool*[m];
        for (int i = 0; i < m; ++i)
        {
            visited[i] = new bool[n];
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                visited[i][j] = false;
            }
        }      
        return dfs(image, sr, sc, newColor, visited, m, n, startColor);
    }
};







