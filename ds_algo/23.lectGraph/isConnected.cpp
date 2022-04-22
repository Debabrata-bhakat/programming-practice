#include <iostream>
using namespace std;

void DFS(int** edges,int n, int sv, int* visited){
	visited[sv] = true;
	for (int i = 0; i < n; ++i)
	{
		if(edges[sv][i]==1 and !visited[i]){
			DFS(edges, n, i, visited);
		}
	}
}

bool isConnected(int** edges, int n){
	int* visited = new int[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
	}
	// do one dfs
	DFS(edges,n,0,visited);
	for (int i = 0; i < n; ++i)
	{
		if(!visited[i]) return false;
	}
	return true;
}


int main(){
	int n;
	int e;
	cin >>n >> e;
	int** edges = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			edges[i][j] = 0;
		}
	}
	for (int i = 0; i < e; ++i)
	{
		int f,s; cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	cout << isConnected(edges,n) << endl;
}
