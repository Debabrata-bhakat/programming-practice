// https://practice.geeksforgeeks.org/problems/topological-sort/1
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	int findMin(int* inEdge, int V){
		int vertex=-1;
		for (int i = 0; i < V; ++i)
		{
			if(inEdge[i]==0) return i;
		}
		return 0;
	}
	void findInEdges(int* inEdge, int V, vector<int> adj[]){
		for (int i = 0; i < V; ++i)
	    {
	    	inEdge[i] = adj[i].size();
	    }
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int* inEdge = new int[V];
	    findInEdges(inEdge,V, adj);
	    vector<int> res;
	    for (int i = 0; i < V; ++i)
	    {
	    	int vertex = findMin(inEdge,V);
	    	// remove all edges of vertex
	    	vector<int> temp;
	    	adj[vertex] = temp;
	    	findInEdges(inEdge,V,adj);
	    	res.push_back(vertex);
	    }
	    for (int i = 0; i < res.size(); ++i)
	    {
	    	cout << res[i] << " ";
	    }
	    cout << endl;
	    return res;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends