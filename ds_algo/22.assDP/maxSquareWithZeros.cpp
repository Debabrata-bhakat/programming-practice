#include <iostream>
using namespace std;

int solve(int** a, int n, int m){
    int** dp = new int*[n];
    for(int i = 0; i < (n); ++i)
        dp[i] = new int[m];
    // fill the first row
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = a[0][i]==0;
    }
    // fill the first column
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = a[i][0]==0;
    }
    // fill the rest of cells
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if(a[i][j]==1){
                dp[i][j] = 0; 
                continue;
            }
            dp[i][j] = min( dp[i-1][j-1], min( dp[i-1][j], dp[i][j-1] ) ) + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans = max(ans,dp[i][j]);
        }
    }
    return ans;
}

int main(){
	int n, m; cin >> n >> m;
    int** a = new int*[n];
    for(int i = 0; i < (n); ++i)
        a[i] = new int[m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
        
    }
    cout << solve(a, n, m) << endl;
}
