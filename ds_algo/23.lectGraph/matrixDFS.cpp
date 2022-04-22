#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
#define ROW 3
#define COL 3

bool isValid(int row, int col, bool vis[][COL]){
	if(row<0 or col<0 or row>=ROW or col>=COL) return false;
	if(vis[row][col]) return false;
	return true;
}

// using stack
void DFS_stack(bool vis[][COL], int dRow[], int dCol[], int grid[][COL], int row, int col){
	stack<pair<int,int>> st;
	st.push({row,col});
	// mark visited
	vis[row][col] = true;	
	while(!st.empty()){
		// pop the top element
		pair<int,int> curr = st.top();
		st.pop();
		int row = curr.first; int col = curr.second;
		// print the current element
		cout << grid[row][col] << endl;
		for (int i = 0; i < 4; ++i)
		{
			int adjx = row + dRow[i];
			int adjy = col + dCol[i];
			// check if the adjacent cell is valid 
			if(!isValid(adjx, adjy, vis)) continue;
			st.push({adjx,adjy});
			// mark visited
			vis[adjx][adjy] = true;	
		}
	}
}

// using recursion
void DFS_recursion(bool vis[][COL], int dRow[], int dCol[], int grid[][COL], int row, int col){
	vis[row][col] = true;
	cout << grid[row][col] << endl;
	// go to all adjacent cells
	for (int i = 0; i < 4; ++i)
	{
		int adjx = row + dRow[i];
		int adjy = col + dCol[i];
		if(!isValid(adjx,adjy, vis)) continue;
		DFS_recursion(vis, dRow, dCol, grid, adjx, adjy);
	}
}

int main(){
	int dRow[] = {0,1,0,-1};
	int dCol[] = {-1,0,1,0};
	int grid[ROW][COL] = { { -1, 2, 3 },
                           { 0, 9, 8 },
                           { 1, 0, 1 } };
    bool vis[ROW][COL];
    memset(vis, false, sizeof vis);
    // function call
    DFS_recursion(vis, dRow, dCol, grid, 0, 0);
}