// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1#
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    	vector<int> output;
    	int* visited = new int[V];
    	for (int i = 0; i < V; ++i)
    	{
    		visited[i] = false;
    	}
    	queue<int> pendingVertices;
    	pendingVertices.push(0);
    	visited[0] = true;
    	while(!pendingVertices.empty()){
    		int currentVertex = pendingVertices.front();
    		pendingVertices.pop();
    		output.push_back(currentVertex);
    		vector<int> connected = adj[currentVertex];
    		for (int i = 0; i < connected.size(); ++i)
    		{
    			if(visited[connected[i]]) continue;
    			pendingVertices.push(connected[i]);
				visited[connected[i]] = true;
    		}
    	}
    	return output;
        // Code here
    }
};