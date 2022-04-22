// https://practice.geeksforgeeks.org/problems/alien-dictionary/1
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        // make the graph
        string res="";
        unordered_map<char, vector<char>> edges;
        vector<int> inEdge(K,0);
        for (int i = 1; i < N; ++i)
        {
            string word1 = dict[i-1], word2 = dict[i];
            for (int j = 0; j < min(word1.size(),word2.size()); ++j)
            {
                if(word1[j]!=word2[j]){
                    edges[word1[j]].push_back(word2[j]);
                    inEdge[word2[j]-'a']++;
                    break;
                } 
                
            }
        }
        // find topo sort
        queue<char> q;
        for (int i = 0; i < K; ++i)
        {
            if(!inEdge[i]) q.push((char)(i+'a'));
        }
        while(q.size()){
            char curr = q.front(); q.pop();
            for (int i = 0; i < edges[curr].size(); ++i)
            {
                if((--inEdge[edges[curr][i]-'a'])==0){
                    res += (char)edges[curr][i];
                    q.push(edges[curr][i]);
                }
            }
        }
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