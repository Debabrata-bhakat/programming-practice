#include <iostream>
#include <queue>
using namespace std;

vector<int> BFS(int** edges,int n, int sv, bool* visited){
	queue<int> pendingVertices;
	pendingVertices.push(sv);
	visited[sv] = true;
	vector<int> ans;
	ans.push_back(sv);
	while(!pendingVertices.empty()){
		int currentVertex = pendingVertices.front();
		pendingVertices.pop();
		for (int i = 0; i < n; ++i)
		{
			if(edges[currentVertex][i] and !visited[i]){
				visited[i] = true;
				pendingVertices.push(i);
				ans.push_back(i);
			}
		}
	}
	return ans;
}

vector<vector<int>> allComp(int** edges, int n){
	vector<vector<int>> ans;
	bool* visited = new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
	}
	for (int i = 0; i < n; ++i)
	{
		if(!visited[i]){
			vector<int> smallOutput = BFS(edges, n, i, visited);
			ans.push_back(smallOutput);
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
	vector<vector<int>> ans = allComp(edges,n);
	for (int i = 0; i < ans.size(); ++i)
	{
		for (int j = 0; j < ans[i].size(); ++j)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}
