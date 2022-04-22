#include <iostream>
using namespace std;

int solve_DP(int* a, int s, int e){
    int** dp = new int*[e+1];
    for(int i = 0; i < (e+1); ++i)
        dp[i] = new int[e+1];

    // fill with default values
    for (int i = 0; i < e+1; i++)
    {
        for (int j = 0; j < e+1; j++)
        {
            dp[i][j] = -1;
        }
    }
    // fill the lower triangle
    for (int i = 0; i < e+1; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = e; i >= 0; i--)
    {
        for (int j = 0; j < e+1; j++)
        {
            if(dp[i][j] == 0) continue;
            if(i+1==j) {
                dp[i][j] = 0;
                continue;
            }
            int ans = INT16_MAX;
            for (int k = i+1; k <= j-1; k++)
            {
                int x = dp[i][k] + dp[k][j] + a[i]*a[k]*a[j];
                ans = min(ans, x);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][e];
}

int solve_mem(int* a, int** dp, int s, int e){
    // Base case
    if(s==e or s+1==e) return 0;

    // check if answer already exists
    if(dp[s][e] != -1) return dp[s][e];

    // recursive calls
    int ans = INT16_MAX;
    for (int i = s+1; i <= e-1; i++)
    {
        int x = solve_mem(a, dp, s,i) + solve_mem(a, dp,i,e) + a[s]*a[i]*a[e];
        ans = min(ans,x);
    }
    // save answer
    dp[s][e] = ans;
    return ans;
}

int solve_mem(int *a, int s, int e){
    int** dp = new int*[e+1];
    for(int i = 0; i < (e+1); ++i)
        dp[i] = new int[e+1];
    for (int i = 0; i < e+1; i++)
    {
        for (int j = 0; j < e+1; j++)
        {
            dp[i][j] = -1;
        }
    }
    return solve_mem(a, dp, s, e);
}

int solve(int *a, int s, int e){
    // Base case
    if(s==e or s+1==e) return 0;

    // recursive calls
    int ans = INT16_MAX;
    for (int i = s+1; i <= e-1; i++)
    {
        int x = solve(a,s,i) + solve(a,i,e) + a[s]*a[i]*a[e];
        ans = min(ans,x);
    }
    return ans;
}

int main(){
    int n; cin >> n;
    int *a = new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        cin >> a[i];
    }
    cout << solve_mem(a,0,n) << endl;
    cout << solve_DP(a,0,n) << endl;
    cout << solve(a,0,n) << endl;
}