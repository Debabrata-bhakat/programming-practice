// A C++ program to Clone an Undirected Graph
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// A function which clones a Graph and
// returns the address to the cloned
// src node
Node* cloneGraph(Node* node) {
	if(node==NULL) return NULL;
        map<int, Node*> m;
        Node* clone = new Node(node->val);
        queue<Node*> pending;
        pending.push(node);
        m[clone->val] = clone;
        while(!pending.empty()){
            Node* curr = pending.front();
            pending.pop();
            vector<Node*> neigh = curr->neighbors;

            for(int i = 0; i< neigh.size(); i++){
        	// cout << "lsdkjf\n";
                Node* currN = neigh[i];
                if(m.count(currN->val)==0){
                    Node* newNode = new Node(currN->val);
                    pending.push(currN);
                    m[currN->val] = newNode;
                }
                // cout << "value: " << curr->val << "neighbors: " << m[currN->val]->val; 
                m[curr->val]->neighbors.push_back(m[currN->val]);
            }
        }
        return m[node->val];
    }

// Build the desired graph
Node *buildGraph()
{
	/*
		Note : All the edges are Undirected
		Given Graph:
		1--2
		| |
		4--3
	*/
	Node *node1 = new Node();
	node1->val = 1;
	Node *node2 = new Node();
	node2->val = 2;
	Node *node3 = new Node();
	node3->val = 3;
	Node *node4 = new Node();
	node4->val = 4;
	vector<Node *> v;
	v.push_back(node2);
	v.push_back(node4);
	node1->neighbors = v;
	v.clear();
	v.push_back(node1);
	v.push_back(node3);
	node2->neighbors = v;
	v.clear();
	v.push_back(node2);
	v.push_back(node4);
	node3->neighbors = v;
	v.clear();
	v.push_back(node3);
	v.push_back(node1);
	node4->neighbors = v;
	return node1;
}

// A simple bfs traversal of a graph to
// check for proper cloning of the graph
void bfs(Node *src)
{
	map<Node*, bool> visit;
	queue<Node*> q;
	q.push(src);
	visit[src] = true;
	while (!q.empty())
	{
		Node *u = q.front();
		cout << "Value of Node " << u->val << "\n";
		cout << "Address of Node " <<u << "\n";
		q.pop();
		vector<Node *> v = u->neighbors;
		int n = v.size();
		for (int i = 0; i < n; i++)
		{
			if (!visit[v[i]])
			{
				visit[v[i]] = true;
				q.push(v[i]);
			}
		}
	}
	cout << endl;
}

// Driver program to test above function
int main()
{
	Node *src = buildGraph();
	cout << "BFS Traversal before cloning\n";
	bfs(src);
	Node *newsrc = cloneGraph(src);
	cout << "BFS Traversal after cloning\n";
	bfs(newsrc);
	return 0;
}
