#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(bool* visited, int* weights, int n){
	int minVertex = -1; int min_weight = INT16_MAX;
	for (int i = 0; i < n; ++i)
	{
		if(visited[i]) continue;
		if(min_weight>weights[i]){
			minVertex = i; min_weight = weights[i];
		}
	}
	return minVertex;
}

void dijkstras(int** edges, int n){
	bool* visited = new bool[n];
	int* weights = new int[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
		weights[i] = INT_MAX;
	}

	weights[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		// find vertex with smalles weight
		int minVertex = findMinVertex(visited, weights, n);
		visited[minVertex] = true;
		// explore all adjacent vertices
		for (int j = 0; j < n; ++j)
		{
			if(!edges[minVertex][j]) continue;
			if(visited[j]) continue;
			if(weights[j] < weights[minVertex] + edges[minVertex][j]) continue;
			weights[j] = weights[minVertex] + edges[minVertex][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << i << " " << weights[i] << endl;
	}
}

int main(){
	int n,E; cin >> n >> E;
	int** edges = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			edges[i][j] = 0;
		}
	}
	for (int i = 0; i < E; ++i)
	{
		int s,d,w; cin >> s >> d >> w;
		edges[s][d] = w; edges[d][s] = w;
	}
	dijkstras(edges, n);
}