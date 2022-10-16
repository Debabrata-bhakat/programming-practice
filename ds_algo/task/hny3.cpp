#include <bits/stdc++.h>
#define ull unsigned long long 
using lli = long long int;
using namespace std;
int mod = 1e9+7;
void solve();
// calculate a^b mod 10^9+7
lli binary_exponentiation(lli a, lli b,  lli mod){
   lli ans=1;
   while(b>0){
      if(b%2==1){
         ans = (ans*a) % mod;
      }
      a = (a*a) %mod;
      b/=2;
   }
   return ans;
}

int gcd(int a, int b){
   if(a==0 or b==0) return a^b;
   return __gcd(a,b);
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    cin >> t;
    // t=1;
    while(t--) solve();
}
int n;
vector<vector<int>> global_graph;
vector<int> visited;

void dfs(int v,int c){
   visited[v]=c;
   for(auto x:global_graph[v]){
      if(!visited[x])dfs(x,c);
   }
}

int connectedSum(int graph_nodes, vector<int> graph_from, vector<int> graph_to){
   n = graph_nodes;
   global_graph.clear(); global_graph.resize(n+1);
   visited.clear(); visited.resize(n+1);
   for(int i=0;i<graph_to.size();i++){
      global_graph[graph_to[i]].push_back(graph_from[i]);
      global_graph[graph_from[i]].push_back(graph_to[i]);
   }
   int present = 1;
   for(int i=1;i<=n;i++){
      if(!visited[i]){
         dfs(i,present);
         present++;
      }
   }
   int ans = 0;
   map<int,int> mp;
   for(int i=1;i<=n;i++){
      mp[visited[i]]++;
   }
   for(auto &x:mp){
      int y = x.second;
      y = sqrt(y);
      if(y*y<x.second)y++;
      ans+=y;
   }
   return ans;
}

void solve(){
   int n;cin>>n;
   int m;cin>>m;
   vector<int> arr1(m); vector<int> arr2(m);
   for(int i=0;i<m;i++) cin>>arr1[i];
   for(int i=0;i<m;i++) cin>>arr2[i];
      cout << connectedSum(n,arr1,arr2) << endl;
}