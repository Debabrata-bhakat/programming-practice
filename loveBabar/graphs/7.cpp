// https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    class Cell{
    public:
    	int x;
    	int y;
    	int dis;
    	Cell(){};
    	Cell(int x, int y, int dis):x(x),y(y),dis(dis){}
    };

    int dx[8] = {1,2,2,1,-1,-2,-2,-1};
    int dy[8] = {2,1,-1,-2,-2,-1,1,2};

    bool isValid(int N, int r, int c, bool** visited){
    	if(r<1 or c<1 or r>N or c>N or visited[r][c]) return false;
    	else return true;
    }

    int bfs(vector<int>&KnightPos, vector<int>&TargetPos, int N, bool** visited){
    	queue<Cell> pendingVertices;
    	Cell ver(KnightPos[0],KnightPos[1],0);
    	pendingVertices.push(ver);
    	visited[KnightPos[0]][KnightPos[1]] = true;
    	while(!pendingVertices.empty()){
    		Cell currVert = pendingVertices.front();
    		pendingVertices.pop();
    		int x = currVert.x, y = currVert.y, dis = currVert.dis;
    		// if the current vertix is target
    		if(x==TargetPos[0] and y==TargetPos[1]) return dis;
    		for (int i = 0; i < 8; ++i)
    		{
    			int adjx = x + dx[i], adjy = y + dy[i];
    			if(!isValid(N,adjx,adjy,visited)) continue;
    			Cell ver(adjx, adjy, dis+1);
    			pendingVertices.push(ver);
    			visited[adjx][adjy] = true;
    		}
    	}
    	return -1;
    }
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    bool** visited = new bool*[N+1];
        for (int i = 0; i < N+1; ++i)
        {
            visited[i] = new bool[N+1];
        }
        for (int i = 0; i < N+1; ++i)
        {
        	for (int j = 0; j < N+1; ++j)
        	{
        		visited[i][j] = false;
        	}
        }
        return bfs(KnightPos, TargetPos, N, visited);

	}





















	// int helper(vector<int> KnightPos, vector<int> TargetPos, int N, bool** visited){
    // 	// mark visited
	   //  cout << "he\n";
    // 	int r = KnightPos[0], c = KnightPos[1];
    // 	int ans = INT16_MAX;
    // 	// if already visited then return
    // 	if(visited[r][c]) return ans;
    // 	// if target reached then return 1
    // 	// if(KnightPos[0]==TargetPos[0] and KnightPos[1]==TargetPos[1]) return 1;
    // 	// marked current one visited
    // 	visited[r][c] = true;
    // 	for (int i = 0; i < 4; ++i)
    // 	{
    // 		int adjx = r + dRow[i], adjy = c + dCol[i];
    // 		if(!isValid(N,adjx,adjy,visited)) continue;
    // 		if(adjx==TargetPos[0] and adjy==TargetPos[1]) return 1;
    // 		vector<int> knight{adjx,adjy};
    // 		ans = min(ans,helper(knight, TargetPos, N, visited));
    // 	}
    // 	visited[r][c] = false;
    // 	return ans+1;
    // }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends