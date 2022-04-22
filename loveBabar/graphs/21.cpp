// https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	class Edge{
		public:
			int source;
			int dest;
			int weight;
	};
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> weight{n,INT_MAX};
	    weight[0]=0;
	    for (int i = 0; i < n-1; ++i)
	    {
			for(auto edge: edges){
				if(weight[edge[1]] > weight[edge[0]]+weight[edge[2]]) weight[edge[1]] = weight[edge[0]]+weight[edge[2]] 
			}
	    }
		for(auto edge: edges){
			if(weight[edge[1]] > weight[edge[0]]+weight[edge[2]]) weight[edge[1]] = weight[edge[0]]+weight[edge[2]] 
		}
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends

/*

