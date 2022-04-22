// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
// { Driver Code Starts
// Initial Template for C

// Program to count islands in boolean 2D matrix
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define COL 501


 // } Driver Code Ends
// User function Template for C
int dRow[8] = {-1,-1,-1,0,1,1,1,0};
int dCol[8] = {-1,0,1,1,1,0,-1,-1};
bool isValid(int M[][COL], int n, int m, bool** visited, int r, int c){
	if(r<0 or c<0 or r>=n or c>=m){
		return false;	
	} 
	if(visited[r][c] or !M[r][c]){
		return false;	
	} 
	return true;
}
void dfs(int M[][COL], int n, int m, bool** visited, int r, int c){
	visited[r][c]=true;
	for (int i = 0; i < 8; ++i)
	{
		int adjx=r+dRow[i],adjy=c+dCol[i];

		if(isValid(M,n,m,visited,adjx,adjy)) {
			// printf("he\n");
			dfs(M,n,m,visited,adjx,adjy);
		}
	}
}
int countIslands(int M[][COL], int n, int m) {
    // your code goes here
    bool** visited = new bool*[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = new bool[m];
		for (int j = 0; j < m; ++j)
		{
			visited[i][j]=false;
		}
	}
	int res=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(!visited[i][j] and M[i][j]){
				res++;
				dfs(M,n,m,visited,i,j);
			}
		}
	}
	return res;

}




// { Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {

        int n, m;
        scanf("%d %d", &n, &m);

        int M[n][COL];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &M[i][j]);
            }
        }

        int ans = countIslands(M, n, m);
        printf("%d\n", ans);
    }

    return 0;
}
  // } Driver Code Ends
/*
1
4 2
0 1
1 0
1 1
1 0
*/