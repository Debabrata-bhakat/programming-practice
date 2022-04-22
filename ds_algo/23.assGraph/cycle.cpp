#include <iostream>
using namespace std;

int cycle(int** edges, int n){
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(!edges[i][j]) continue;
			for (int k = 0; k < n; ++k)
			{
				if(edges[k][j] and edges[k][i]) ans++;
			}
		}
	}
	return ans/6;
}

int main(){
	int n,m; cin >> n >> m;
	int** edges = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		edges[i] = new int[n];
	}
	for (int i = 0; i < m; ++i)
	{
			int s,d; cin >> s >> d;
			edges[s][d] = 1;
			edges[d][s] = 1;
	}
	cout << cycle(edges, n) << endl;
}