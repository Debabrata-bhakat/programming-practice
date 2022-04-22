#include <iostream>
#include <vector>
using namespace std;

vector<int> getPathDFS(int** edges, int n, int sv, int ev, bool* visited){
	visited[sv] = true;
	// base case : if target and source are same
	if(sv==ev){
		vector<int> ans;
		ans.push_back(sv);
		return ans;
	}

	// recursive calls
	for (int i = 0; i < n; ++i)
	{
		if(edges[sv][i] and !visited[i]){
			vector<int> ans = getPathDFS(edges,n,i,ev,visited);
			if(ans.size()>0){
				ans.push_back(sv);
				return ans;	
			}
		}
	}
	vector<int> a;
	return a;
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
	vector<int> path = getPathDFS(edges, n, sv, ev, visited);
	for (int i = 0; i < path.size(); ++i)
	{
		cout << path[i] << " ";
	}
}
