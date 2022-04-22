#include <iostream>
using namespace std;

// down, up, right, left
int dRow[] = {1, -1, 0, 0};
int dCol[] = {0, 0, 1, -1};
bool findCycle = false;

void DFS(char** edges, int r, int c, int from_r, int from_c, int maxRow, int maxCol, bool** visited, char search){
	// if it is out of bounds
	if(r<0 or c<0 or r>=maxRow or c>=maxCol) return;
	// if character is not same
	if(edges[r][c]!=search) return;
	// if it completes the loop
	if(visited[r][c]){
		findCycle = true;
		return;
	}

	visited[r][c] = true;
	for (int i = 0; i < 4; ++i)
	{
		int adjx = r + dRow[i]; int adjy = c + dCol[i];
		// check if it does not go back to previous cell
		if(adjx==from_r and adjy==from_c) continue;
		DFS(edges, adjx, adjy, r, c, maxRow, maxCol, visited, search);
	}
}

void connectingGraphs(char** edges, int n, int m){
	int dRow[] = {0,0,1,-1};
	int dCol[] = {1,-1,0,0};
	bool** visited = new bool*[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = new bool[m];
		for (int j = 0; j < m; ++j)
		{
			visited[i][j]=false;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(!visited[i][j]) DFS(edges, i, j, -1, -1, n, m, visited, edges[i][j]);
		}
	}
	cout << (findCycle?"Yes":"No") << endl;
}

int main(){
	int n,m; cin>>n>>m;
	char** edges = new char*[n];
	for (int i = 0; i < n; ++i)
	{
		edges[i] = new char[m];
		for (int j = 0; j < m; ++j)
		{
			cin >> edges[i][j];
		}
	}
	connectingGraphs(edges, n, m);
}