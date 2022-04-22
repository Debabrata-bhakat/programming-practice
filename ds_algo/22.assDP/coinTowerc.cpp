#include <iostream>
using namespace std;

int solve_DP(int n, int x, int y){
    int* dp = new int[n+1];
    for (int i = 0; i < n+1; ++i)
    {
        dp[i] = -1;
    }
    dp[1]=1; dp[x]=1; dp[y]=1;
    for (int i = 2; i < n+1; i++)
    {
        if(dp[i]!=-1) continue;
        int a=1, b=1, c=1;
        if(i>x) a = dp[i-x];
        if(i>y) b = dp[i-y];
        c = dp[i-1];
        if(a==0 or b==0 or c==0) dp[i] = 1;
        else dp[i] = 0;
    }
    return dp[n];
}


int solve_mem(int* dp, int n, int x, int y){
    // base case
    if(n==1 or n==x or n==y) return 1;

    // check if answer already exists
    if(dp[n] != -1) return dp[n];

    // recursive calls
    int a=1;
    int b = 1;
    int c = 1;
    int ans;
    if(n>x) a = solve_mem(dp, n-x, x, y);
    if(n>y) b = solve_mem(dp, n-y, x, y);
    c = solve_mem(dp, n-1, x, y);
    if(a==0 or b==0 or c==0) ans = 1;
    else ans = 0;
    // save answer
    dp[n] = ans;
    return ans;

}
int solve_mem(int n, int x, int y){
    int* dp = new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        dp[i] = -1;
    }
    return solve_mem(dp, n, x, y);
}
int solve(int n, int x, int y){
    // base case
    if(n==1 or n==x or n==y) return 1;

    // recursive calls
    int a=1;
    int b = 1;
    int c = 1;
    if(n>x) a = solve(n-x, x, y);
    if(n>y) b = solve(n-y, x, y);
    c = solve(n-1, x, y);
    if(a==0 or b==0 or c==0) return 1;
    else return 0;
}

int main(){
    int n, x, y; cin >> n >> x >> y;
    cout << solve(n,x,y) << endl;
    cout << solve_mem(n, x, y) << endl;
    cout << solve_DP(n, x, y) << endl;
}