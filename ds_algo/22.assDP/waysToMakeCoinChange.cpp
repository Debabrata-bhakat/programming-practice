#include <iostream>
using namespace std;

int solve_DP(int *a, int n, int sum){
    int** dp = new int*[n+1];
    for(int i = 0; i < (n+1); ++i)
        dp[i] = new int[sum+1];

    // fill first column
    for (int i = 0; i < n+1; i++)
    {
        dp[i][0] = 1;
    }

    // fill the first row
    for (int i = 0; i < sum+1; i++)
    {
        dp[0][i] = 0;
    }
    
    // fill the rest of the cells
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            int x = dp[i-1][j];
            if(j-a[n-i] >= 0){
                int y = dp[i][j-a[n-i]];
                dp[i][j] = x + y;
            }else{
                dp[i][j] = x;
            }
        }
    }
    return dp[n][sum];
}

int solve_mem(int **dp, int* a, int n, int sum){
    // Base case
    if(sum==0) return 1;
    if(n<=0 or sum<0) return 0;

    // check if answer already exists
    if(dp[n][sum] != -1) return dp[n][sum];

    // recursive calls
    int x = solve_mem(dp, a+1, n-1, sum);        // do not take the first number
    // int y = solve(a+1, n-1, sum-a[0]);   // take the first number one time
    int z = solve_mem(dp, a, n, sum-a[0]);       // take the first number multiple times
    dp[n][sum] = x+z;
    return x+z;

}

int solve_mem(int* a, int n, int sum){
    int** dp = new int*[n+1];
    for(int i = 0; i < (n+1); ++i)
        dp[i] = new int[sum+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            dp[i][j] = -1;
        }
    }
    return solve_mem(dp, a, n, sum);
}

int solve(int* a, int n, int sum){
    // Base case
    if(sum==0) return 1;
    if(n<=0 or sum<0) return 0;

    // recursinve calls
    int x = solve(a+1, n-1, sum);        // do not take the first number
    // int y = solve(a+1, n-1, sum-a[0]);   // take the first number one time
    int z = solve(a, n, sum-a[0]);       // take the first number multiple times
    return x+z;
}

int main(){
    int n; cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum; cin >> sum;
    // cout << solve(a, n, sum) << endl;
    // cout << solve_mem(a, n, sum) << endl;
    cout << solve_DP(a, n, sum) << endl;
}