#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{

public:	
	int source;
	int dest;
	int weight;
	Edge(){};
	Edge(int source, int dest, int weight){
		this->source = source;
		this->dest = dest;
		this->weight = weight;
	}	
};

bool valueCmp(Edge const & a,Edge const & b ){
	return a.weight < b.weight;
}

// int getParent(int vertex, int* parents){
// 	int parent = parents[vertex];
// 	while(parent!=vertex){
// 		vertex = parent;
// 		parent = parents[vertex];
// 	}
// 	return parent;
// }

int getParent(int v, int* parent){
	if(parent[v]==v) return v;
	return getParent(parent[v], parent);
}

int main(){
	int n, e; cin >> n >> e;
	Edge* input = new Edge[e];
	Edge* output = new Edge[n-1];

	// take input
	for (int i = 0; i < e; ++i)
	{
		int s,d,w; cin >> s >> d >> w;
		Edge temp(s,d,w);
		input[i] = temp;
	}

	// sort it in increasing order
	sort(input, input+e, valueCmp);

	// make the parents array
	int* parents = new int[n];
	for (int i = 0; i < n; ++i)
	{
		parents[i] = i;
	}


	int count = 0, arrIndex=0;
	while(count<n-1){

		// take the smallest weight
		Edge currEdge = input[arrIndex++];
		int currSource = currEdge.source;
		int currDest = currEdge.dest;
		int currWeight = currEdge.weight;

		// get the parents of the vertices
		int parentSource = getParent(currSource, parents), parentDest = getParent(currDest, parents);

		// if the parents are same then skip the edge
		if(parentSource==parentDest) continue;

		// else make both parents same
		parents[parentSource] = parentDest;

		// add the edge to output
		// increase the number of edges by one
		Edge addEdge(currSource, currDest, currWeight);
		output[count++] = addEdge;
	}

	cout << "The minimum spanning tree formed is \n";
	// Print the MST
	for (int i = 0; i < n-1; ++i)
	 {
	 	cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
	 } 
}