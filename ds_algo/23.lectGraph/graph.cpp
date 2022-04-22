#include <iostream>
#include <queue>
#include <vector>
using namespace std;



void printDFS(int** edges, int n, int sv, bool* visited){
	cout << sv << " ";
	visited[sv] = true;
	for (int i = 0; i < n; ++i)
	{
		if(i==sv) continue;
		if(edges[sv][i] == 1){
			// if it is already visited
			if(visited[i]) continue;
			printDFS(edges, n, i, visited);
		}
	}
}

void printBFS(int** edges, int n, int sv, bool* visited){
	queue<int> pendingVertices;
	pendingVertices.push(sv);
	visited[sv] = true;
	while(!pendingVertices.empty()){
		int currentVertex = pendingVertices.front();
		pendingVertices.pop();
		cout << currentVertex << " ";
		for (int i = 0; i < n; ++i)
		{
			if(edges[currentVertex][i]==1 and !visited[i]){
				pendingVertices.push(i);
				visited[i] =true;
			}
		}
	}
}

void BFS(int** edges, int n){
	bool* visited = new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
	}
	for (int i = 0; i < n; ++i)
	{
		if(!visited[i]) printBFS(edges,n,i,visited); 
	}
	delete [] visited;

}

void DFS(int** edges, int n){
	bool* visited = new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
	}
	for (int i = 0; i < n; ++i)
	{
		if(!visited[i]) printDFS(edges,n,i,visited); 
	}
	delete [] visited;
}


bool hasPath(int** edges, int n, int sv, int ev, bool* visited){
	visited[sv] = true;
	// base case : check adjacent vertices
	for (int i = 0; i < n; ++i)
	{
		if(edges[sv][ev]==1) return true;
	}

	// recursive calls
	for (int i = 0; i < n; ++i)
	{
		if(edges[sv][i]==1 and !visited[i] and hasPath(edges, n, i, ev, visited)) return true;
	}
	return false;
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
	bool* visited = new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
	}
	cout << "DFS\n";
	DFS(edges,n);
	cout << "\nBFS\n";
	BFS(edges,n);
	cout << "\nPath\n";

	int sv,ev; cin >> sv >> ev;
	cout << hasPath(edges,n,sv,ev,visited) << endl;
}

//////////////////////////////////////////////// BY ME ///////////////////////


// void bfs(int** edges,int n, int sv){
// 	queue<int> pendingData;
// 	bool* visited = new bool[n];
// 	for (int i = 0; i < n; ++i)
// 	{
// 		visited[i] = false;
// 	}
// 	pendingData.push(sv);
// 	visited[sv] = true;
// 	while(!pendingData.empty()){
// 		int curr_data = pendingData.front();
// 		cout << curr_data << " ";
// 		pendingData.pop();
// 		for (int i = 0; i < n; ++i)
// 		{
// 			if(i==curr_data) continue;
// 			if(edges[curr_data][i]==1){
// 				// if it is already visited
// 				if(visited[i]) continue;
// 				pendingData.push(i);
// 				visited[i] = true;
// 			}
// 		}
// 	}
// 	cout << endl;
// }