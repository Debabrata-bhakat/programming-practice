// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/

#include <iostream>
#include <algorithm>
using namespace std;

class Edge{
public:
	int source;
	int dest;
	int weight;
};
int getParent(int* parent, int n){
	if(n==parent[n]) return n;
	return getParent(parent, parent[n]);
}
bool compare(Edge e1, Edge e2){
	return e1.weight < e2.weight;
}
void kruskals(Edge* input, int n, int E){
	// sort the edges in ascending order
	Edge* output = new Edge[n-1];
	sort(input, input+E, compare);
	int* parent = new int[n];
	for (int i = 0; i < n; ++i)
	{
		parent[i] = i;
	}
	int count=0,i=0;
	while(count!=n-1){
		Edge curr = input[i++];
		// check if cycle is formed
		int parent1 = getParent(parent, curr.source), parent2 = getParent(parent, curr.dest);
		if(parent1==parent2) continue;
		parent[parent1] = parent2;
		output[count++] = curr;
	}
	for (int i = 0; i < n-1; ++i)
	{
		if(output[i].source < output[i].dest) cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
		else cout << output[i].dest << " " << output[i].weight << " " << output[i].source << endl;
	}
}

int main(){
	int n,E;cin>>n>>E;
	Edge* input = new Edge[E];
	for (int i = 0; i < E; ++i)
	{
		int s,d,w;cin>>s>>d>>w;
		input[i].source=s;input[i].dest=d;input[i].weight=w;
	}
	cout << endl;
	kruskals(input,n,E);
}