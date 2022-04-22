#include <iostream>
using namespace std;
int dRow[] = {1, -1, 0, 0};
int dCol[] = {0, 0, 1, -1};


bool isValid(int** edges, int n, int r, int c, bool** visited){
	if(r<0 or c<0 or r>=n or c>=n) return false;
	if(visited[r][c]) return false;
	return true;
}

int DFS(int** edges, int n, bool** visited, int r, int c){
	visited[r][c] = true;
	int size=0;
	for (int i = 0; i < 4; ++i)
	{
		int adjx = r + dRow[i]; int adjy = c + dCol[i];
		if(!isValid(edges, n, adjx, adjy, visited) or !edges[adjx][adjy]) continue;
		size += DFS(edges, n, visited, adjx, adjy);
	}
	return size+1;
}

int largestPiece(int** edges, int n){
	bool** visited = new bool*[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = new bool[n];
		for (int j = 0; j < n; ++j)
		{
			visited[i][j]=false;
		}
	}
	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(edges[i][j] and !visited[i][j]) ans = max(ans,DFS(edges, n, visited, i, j));
		}
	}
	return ans;
}

int main(){
	int n; cin >> n;
	int** edges = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			cin >> edges[i][j];
		}
	}
	cout << largestPiece(edges,n) << endl;
}