// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isCyclic(vector<int>* adj, int sv, int pv, bool* visited, bool* recStack, int N){
		visited[sv]=true;recStack[sv]=true;
		for (int i = 0; i < adj[sv].size(); ++i)
		{
			if(!visited[adj[sv][i]] and isCyclic(adj,adj[sv][i],sv,visited,recStack,N)) return true;
			if(recStack[adj[sv][i]] )return true;
		}
		recStack[sv]=false;
		return false;
	}
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	   // make the graph
	    vector<int> adj[N];
	    for (int i = 0; i < prerequisites.size(); ++i)
	    {
	    	pair<int,int> curr = prerequisites[i];
	    	int source=curr.second,dest=curr.first;
	    	adj[source].push_back(dest);
	    }
	    bool* visited = new bool[N];
	    bool* recStack = new bool[N];
	    for (int i = 0; i < N; ++i)
	    {
	    	visited[i]=false;recStack[i]=false;
	    }
	    for (int i = 0; i < N; ++i)
	    {
	    	if(!visited[i] and isCyclic(adj,i,-1,visited,recStack,N)) return false;
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends

/*
1
4 3
1 0  2 1  3 2
yes

1
2 2
1 0  0 1
*/