#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> getPathBFS(int** edges,int n, int sv, int ev){
	// create the visited array
	bool* visited = new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
	}

	int flag = 0;
	// create the hashmap which stores the parent vertex
	unordered_map<int,int> seen;
	// queue for storing the pending vertices
	queue<int> pendingVertices;
	pendingVertices.push(sv);
	visited[sv] = true;
	int currentVertex;
	while(!pendingVertices.empty()){
		currentVertex = pendingVertices.front();
		pendingVertices.pop();
		// if the vertex is found then break
		if(currentVertex==ev){
			flag = 1;
			break;
		}
		// go through all of its adjacent vertices
		for (int i = 0; i < n; ++i)
		{
			if(edges[currentVertex][i]==1 and !visited[i]){
				// add that to the queue
				pendingVertices.push(i);
				// add the parent vertex to map
				seen[i] = currentVertex;
				// mark the vertex as visited
				visited[i] = true;
			}
		}
	}
	vector<int> ans;
	if(flag){
		// if found
		ans.push_back(currentVertex);
		while(currentVertex!=sv){
			currentVertex = seen[currentVertex];
			ans.push_back(currentVertex);
		}
	}
	return ans;
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
	int sv,ev; cin >> sv >> ev;
	cout << "Path\n";
	vector<int> path = getPathBFS(edges, n, sv, ev);
	for (int i = 0; i < path.size(); ++i)
	{
		cout << path[i] << " ";
	}
}
