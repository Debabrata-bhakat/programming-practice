#include <iostream>
using namespace std;

int minCost3(int **a, int m, int n){
    int** ans = new int*[m];
    for(int i = 0; i < (m); ++i)
        ans[i] = new int[n];
    // Fill the last cell
    ans[m-1][n-1] = a[m-1][n-1];

    // Fill last row from right to left
    for (int j = n-2; j >= 0; j--)
    {
        ans[m-1][j] = ans[m-1][j+1] + a[m-1][j];
    }

    // Fill last column from bottom to top
    for (int i = m-2; i >= 0; i--)
    {   
        ans[i][n-1] = ans[i+1][n-1] + a[i][n-1];
    }

    // Fill remaining cells
    for (int i = m-2; i >= 0; i--)
    {
        for (int j = n-2; j >= 0; j--)
        {
            ans[i][j] = min( ans[i][j+1], min( ans[i+1][j], ans[i+1][j+1] ) ) + a[i][j];
        }
        
    }
    return ans[0][0];
}

// Memoization
int minCost2_helper(int **a, int ** ans, int m_0, int n_0, int m_1, int n_1){
    // check if answer already exists
    if(ans[m_0][n_0] != INT16_MIN) return ans[m_0][n_0];

    // else calculate the answer
    // if(m_0>m_1 or n_0>n_1) return INT16_MAX;
    // int x = minCost2_helper(a, ans, m_0+1, n_0, m_1, n_1);
    // int y = minCost2_helper(a, ans, m_0, n_0+1, m_1, n_1);
    // int z = minCost2_helper(a, ans, m_0+1, n_0+1, m_1, n_1);
    // ans[m_0][n_0] = min(x, min(y,z)) + a[m_0][n_0];
    // if possile to go down
    int x=INT16_MAX, y=INT16_MAX, z=INT16_MAX;
    if(m_0+1 <= m_1){
        x = minCost2_helper(a, ans, m_0+1, n_0, m_1, n_1);
    }
    // if possible to go right
    if(n_0+1 <= n_1){
        y = minCost2_helper(a, ans, m_0, n_0+1, m_1, n_1);
    }
    // if possible to go diagonal
    if(m_0+1 <= m_1 and n_0+1 <= n_1){
        z = minCost2_helper(a, ans, m_0+1, n_0+1, m_1, n_1);
    }
    // save answer for future use
    ans[m_0][n_0] = min(x, min(y,z)) + a[m_0][n_0];
    // return the answer
    return ans[m_0][n_0];
}

int minCost2(int **a, int m_0, int n_0, int m_1, int n_1){
    // set answers to default values
    int** ans = new int*[m_1+1];
    for(int i = 0; i < (m_1+1); ++i)
        ans[i] = new int[n_1+1];
    for (int i = 0; i < (m_1+1); i++)
    {
        for (int j = 0; j < (n_1+1); j++)
        {
            ans[i][j] = INT16_MIN;
        }
    }
    // save answer for known case
    ans[m_1][n_1] = a[m_1][n_1];
    return minCost2_helper(a, ans, m_0, n_0, m_1, n_1);
}

// Brute force
int minCost(int **a, int m_0, int n_0, int m_1, int n_1){
    // Base case
    if(m_0 == m_1 and n_0 == n_1) return a[m_0][n_0];

    // if possile to go down
    int x=INT16_MAX, y=INT16_MAX, z=INT16_MAX;
    if(m_0+1 <= m_1){
        x = minCost(a, m_0+1, n_0, m_1, n_1);
    }
    // if possible to go right
    if(n_0+1 <= n_1){
        y = minCost(a, m_0, n_0+1, m_1, n_1);
    }
    // if possible to go diagonal
    if(m_0+1 <= m_1 and n_0+1 <= n_1){
        z = minCost(a, m_0+1, n_0+1, m_1, n_1);
    }

    return min(x,min(y,z)) + a[m_0][n_0];
}

int main(){
    int m,n; cin >>m>>n;
    int** a = new int*[m];
    for(int i = 0; i < m; ++i)
        a[i] = new int[n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << minCost(a,0,0,m-1,n-1) << endl;   
    cout << minCost2(a,0,0,m-1,n-1) << endl;   
    cout << minCost3(a, m, n) << endl;
}