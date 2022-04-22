// https://practice.geeksforgeeks.org/problems/alien-dictionary/1
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    pair<int,int> find_source_dest(string w1, string w2){
    	int l = min(w1.length(),w2.length());
    	int source, dest;
    	for (int i = 0; i < l; ++i)
    	{
    		if(w1[i]==w2[i]) continue;
    		source = w1[i]-97, dest = w2[i]-97;
    		break;
    	}
    	pair<int,int> res{source,dest};
    	return res;
    }
    vector<int> topoSort(vector<int> adj[], int V){
        // find in degree of all nodes
        vector<int> res;
        int* inEdge = new int[V];
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < adj[i].size(); ++j)
            {
                inEdge[adj[i][j]]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; ++i)
        {
            if(!inEdge[i]) q.push(i);
        }
        while(q.size()){
            int curr = q.front(); q.pop();
            res.push_back(curr);
            for (int i = 0; i < adj[curr].size(); ++i)
            {
                inEdge[adj[curr][i]]--;
                if(!inEdge[adj[curr][i]]) q.push(adj[curr][i]);
            }
        }
        return res;
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        // make the graph
        string res;
        vector<int>* edges = new vector<int>[K];
        for (int i = 1; i < N; ++i)
        {
        	pair<int,int> temp = find_source_dest(dict[i-1],dict[i]);
        	edges[temp.first].push_back(temp.second);
        }


        // find topological sort
        vector<int> tSort = topoSort(edges,K);
        for (int i = 0; i < tSort.size(); ++i)
        {
            string temp(1,(char)(tSort[i]+97));
            res += temp;
        }
        cout << res << endl;
        return res;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
/*
1  
5 4
baa
abcd
abca
cab
cad
*/