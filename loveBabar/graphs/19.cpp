// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	int findMinVertex(bool* visited, int* weights, int n){
		int minVertex=-1;
		for (int i = 0; i < n; ++i)
		{
			if(!visited[i] and ( minVertex==-1 or weights[minVertex]>weights[i] )) minVertex=i;
		}
		return minVertex;
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        int n=V;
        int** edges = new int*[n];
        for (int i = 0; i < n; ++i)
        {
            edges[i] = new int[n];
            for (int j = 0; j < n; ++j)
            {
                edges[i][j] = 0;
            }
        }
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < adj[i].size(); ++j)
            {
                vector<int> temp = adj[i][j];

                edges[i][temp[0]] = temp[1];
                edges[temp[0]][i] = temp[1];
            }
        }
        int* parent = new int[V];
        bool* visited = new bool[V];
        int* weights = new int[V];
        for (int i = 0; i < V; ++i)
        {
        	visited[i]=false;weights[i]=INT_MAX;
        }
        int res=0;
        weights[0]=0;
        for (int i = 0; i < n-1; ++i)
        {

        	int minVertex = findMinVertex(visited,weights,n);

        	visited[minVertex] = true;
        	// visit all neighbours and update weights
        	for (int j = 0; j < n; ++j)
        	{
        		if(!edges[minVertex][j]) continue;
        		if(visited[j]) continue;
        		// update the weights
        		if(weights[j] > edges[minVertex][j]) weights[j] = edges[minVertex][j];
        	}
        }
        for (int i = 0; i < n; ++i)
        {
        	res+=weights[i];
        }
        return res;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends

/*
1
3 3
0 1 5
1 2 3
0 2 1
*/