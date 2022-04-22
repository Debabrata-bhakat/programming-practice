#include <iostream>
#include <string>
using namespace std;



// pair<int, int> validDir(int** edges, int r, int c, int search, int** visited, int r0, int c0){
// 	pair<int, int> ans;
// 	ans.first = 0; ans.second = 0;
// 	// check @8
// 	if(r0-1>=0 and edges[r0-1][c0]==search and !visited[r0-1][c0]) ans.first == -1;
// 	// check @9
// 	if(r0-1>=0 and c0+1<c and edges[r0-1][c0+1]==search and !visited[r0-1]c0+1){ ans.first=-1; ans.second=1}
// 	// check @6
// 	if(c0+1<c and edges[r0][c0+1]==search and !visited[r0]c0+1) ans.second=1;
// 	// check @3
// 	if(r0+1<r and c0+1<c and edges[r0+1][c0+1]==search and !visited[r0+1][c0+1]) {ans.first=1; ans.second=1}
// 	// check @2
// 	if(r0+1<r and edges[r0+1][c0]==search and !visited[r0+1][c0]) ans.first=1;
// 	// check @1
// 	if(r0+1<r and c0-1>=0 and edges[r0+1][c0-1]==search and !visited[r0+1][c0-1]) {ans.first=1; ans.second=-1}
// 	// check &4
// 	if(c0-1>=0 and edges[r0][c0-1]==search and !visited[r0][c0-1]) ans.second=-1;
// 	// check @7
// 	if(r0-1>=0 and c0-1>=0 and edges[r0-1][c0-1]==search and !visited[r0-1][c0-1]) {ans.first=-1; ans.second=-1}
// 	return ans;
// }

bool isValid(int row, int col, int maxRow, int maxCol, bool** visited){
	if(row<0 or col<0 or row>=maxRow or col>=maxCol) return false;
	if(visited[row][col]) return false;
	return true;
}

bool DFS(char** edges, bool** visited, int row, int col, string search, int dRow[], int dCol[], int maxRow, int maxCol){
	visited[row][col] = true;
	if(!search.length()) return true;
	char ch = search[0];
	bool smallOutput = false;
	for (int i = 0; i < 8; ++i)
	{
		int adjx = row + dRow[i]; int adjy = col + dCol[i];
		if(!isValid(adjx, adjy, maxRow, maxCol, visited)) continue;
		bool tempAns = DFS(edges, visited, adjx, adjy, search.substr(1), dRow, dCol, maxRow, maxCol);
		if(tempAns) smallOutput = tempAns;
	}
	return smallOutput;
}

bool cn(char** edges, int r, int c){
	int dRow[] = {-1,-1,-1,0,0,1,1,1};
	int dCol[] = {-1,0,1,-1,1,-1,0,1};
	// create the visited array
	bool** visited = new bool*[r];
	for (int i = 0; i < r; ++i)
	{
		visited[i] = new bool[c];
		for (int j = 0; j < c; ++j)
		{
			visited[i][j] = false;;
		}
	}

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if(edges[i][j] == 'C'){
				bool output = DFS(edges, visited, i, j, "ODINGNINJAS", dRow, dCol, r, c);
				if(output) return true;
			}
		}
	}
	return false;
}

int main(){
	int r,c; cin >> r >> c;
	char** edges = new char*[r];
	for (int i = 0; i < r; ++i)
	{
		edges[i] = new char[c];
		for (int j = 0; j < c; ++j)
		{
			cin >> edges[i][j];
		}
	}
	cout << '\n' << cn(edges, r, c) << endl;
	// char ch, n,a; cin >> ch >> n>>a;
	// cout << ch << endl;
	// cout << n << endl;
	// cout << a << endl;
}


