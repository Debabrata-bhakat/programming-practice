// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1#


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    int findMin(bool* visited, int* weights, int V){
        int minVertex=-1;
        for(int i=0;i<V;i++){
            if(!visited[i] and (minVertex==-1 or weights[minVertex]>weights[i])){
                minVertex=i;
            }
        }
        return minVertex;
    }
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
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
        // 
        bool* visited = new bool[V];
        int* weights = new int[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
            weights[i] = INT_MAX;
        }
        weights[S]=0;
        for(int i=0;i<V-1;i++){
            int minVertex = findMin(visited,weights,V);
            // mark it as visited
            visited[minVertex]=true;
            for(int j=0;j<V;j++){
                if(!visited[j] and edges[minVertex][j]){
                    int currCost = weights[minVertex] + edges[minVertex][j];
                    // cout << "here     " << weights[minVertex] << endl ;
                    if(currCost<weights[j]) weights[j] = currCost;
                }
            }
        }
        
        vector<int> ans;
        // ans.push_back(0);
        for(int i=0;i<V;i++){
            ans.push_back(weights[i]);
        }
        return ans;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends