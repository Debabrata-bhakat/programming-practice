// https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  	bool isCyclic(int sv, vector<int> adj[], bool* visited, bool* recStack){
  		visited[sv] = true;
  		recStack[sv] = true;
  		for (int i = 0; i < adj[sv].size(); ++i)
  		{
  			if(!visited[adj[sv][i]] and isCyclic(adj[sv][i], adj, visited, recStack)) return true;
  			if(recStack[adj[sv][i]]) return true;
  		}
  		recStack[sv] = false;
  		return false;
  	}
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        bool* visited = new bool[V];
        bool* recStack = new bool[V];
        for (int i = 0; i < V; ++i)
        {
        	visited[i] = false;
        	recStack[i] = false;
        }
        for (int i = 0; i < V; ++i)
        {
        	if(!visited[i] and isCyclic(i, adj, visited, recStack)) return true;
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
/*
4 6
0 1 
0 2
1 2
2 0
2 3
3 3


 4 4
 0 1
 0 2
 1 2
 2 3




*/