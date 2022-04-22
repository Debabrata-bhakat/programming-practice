#include <iostream>
using namespace std;

// DP
int lootHouse_DP(int* a, int n){
    int *dp = new int[n+1];
    dp[0] = 0;
    dp[1] = a[n-1];
    for (int i = 2; i < n+1; i++)
    {
        int x = dp[i-2] + a[n-i];
        int y = dp[i-1];
        dp[i] = max(x,y); 
    }
    return dp[n];
}

// memoisation
int lootHouse_mem(int* a, int n, int *dp){
    // Base case
    if(n<=0) return 0;

    // check if answer already exists
    if(dp[n] != -1) return dp[n];
    // cout << "hello\n";

    // else find the answer
    int x = lootHouse_mem(a+2, n-2, dp) + a[0];
    int y = lootHouse_mem(a+1, n-1, dp);
    // cout << x << " " << y << endl;
    dp[n] = max(x,y);
    return dp[n];
}

int lootHouse_mem(int *a, int n){
    int *dp = new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        dp[i] = -1;
    }
    return lootHouse_mem(a,n,dp);
}

int lootHouse(int* a, int n){
    // Base case
    if(n<=0) return 0;

    // recursive call
    int x = lootHouse(a+2, n-2) + a[0];
    int y = lootHouse(a+1, n-1);
    return max(x,y);
}

int main(){
    int n; cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << lootHouse(a,n) << endl;
    cout << lootHouse_mem(a,n) << endl;
    cout << lootHouse_DP(a,n) << endl;
}