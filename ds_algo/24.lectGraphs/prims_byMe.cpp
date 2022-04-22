#include <iostream>
#include <climits>
using namespace std;

class Edge{
public:
	int source;
	int dest;
	int weight;
};

class Vertex{
public:
	int parent;
	int weight;
	bool visited;
};

void prims(int** edges, int n, int E){
	// create all the vertices
	Vertex* data = new Vertex[n];
	for (int i = 0; i < n; ++i)
	{
		data[i].parent = -1;
		data[i].weight = INT_MAX;
		data[i].visited = false;
	}
	data[0].weight = 0;
	for (int i = 0; i < n; ++i)
	{
		// get the vertex with min weight which is not visited
		int min_vertex = -1; int min_weight = INT16_MAX;
		for (int j = 0; j < n; ++j)
		{
			if(min_weight>data[j].weight and !data[j].visited){
				min_vertex = j; min_weight = data[j].weight;
			}
		}
		// mark the vertex as visited
		data[min_vertex].visited = true;
		// explore all the paths from the vertex
		for (int j = 0; j < n; ++j)
		{
			if(min_vertex==j) continue;
			if(!edges[min_vertex][j]) continue; // if no edge
			if(data[j].weight < edges[min_vertex][j]) continue; // if weight is less than current exploration
			if(data[j].visited) continue; // if vertex visisted then continue
			// update the weight and parent of the explored vertex
			data[j].parent = min_vertex;
			data[j].weight = edges[min_vertex][j];
		}
	}
	// printing the results
	for (int i = 0; i < n; ++i)
	{
		if(data[i].parent==-1) continue;
		cout << i << " " << data[i].parent << " " << data[i].weight << " \n";		
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
	cout << "MST: \n";
	prims(edges, n, E);
}

/*
6 11
0 1 2
1 3 1
0 2 4
2 4 9
4 5 5
3 5 7
4 3 11
2 5 10
0 3 3
2 1 8
2 3 6


1 0 2 
2 0 4 
3 1 1 
4 5 5 
5 3 7 
*/