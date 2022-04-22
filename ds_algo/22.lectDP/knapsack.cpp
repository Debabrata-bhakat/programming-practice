#include <iostream>
using namespace std;

// DP
int knapsack_DP(int* weight, int* value, int n, int maxWeight){
    int** output = new int*[n+1];
    for(int i = 0; i < (n+1); ++i)
        output[i] = new int[maxWeight+1];
    
    // fill the first row
    for (int i = 0; i < maxWeight+1; i++)
    {
        output[0][i] = 0;
    }
    // fill the first column
    for (int i = 0; i < n+1; i++)
    {
        output[i][0] = 0;
    }
    
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < maxWeight+1; j++)
        {
            if( weight[n-i]>j ) output[i][j] = output[i-1][j];
            else{
                int x = output[i-1][j- weight[n-i] ] + value[n-i];
                int y = output[i-1][j];
                output[i][j] = max(x,y);
            }
        }
    }
    return output[n][maxWeight];
}

// memoisation
int knapsack_mem_helper(int *weight, int *value, int n, int maxWeight, int **output){
    // Base case
    if(n==0 or maxWeight==0) return 0;

    // check if solution already exists
    if(output[n][maxWeight] != -1) return output[n][maxWeight];

    // else find the answer
    if(weight[0]>maxWeight) output[n][maxWeight] = knapsack_mem_helper(weight+1, value+1, n-1 , maxWeight, output);

    // recursive calls
    else{
        int x = knapsack_mem_helper(weight+1, value+1, n-1, maxWeight-weight[0], output) + value[0];
        int y = knapsack_mem_helper(weight+1, value+1, n-1, maxWeight, output);
        output[n][maxWeight] = max(x,y);
    }
    return output[n][maxWeight];
}

int knapsack_mem(int* w, int* v, int n, int maxWeight){
    int** output = new int*[n+1];
    for(int i = 0; i < (n+1); ++i)
        output[i] = new int[maxWeight+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < maxWeight+1; j++)
        {
            output[i][j] = -1;
        }
    }
    return knapsack_mem_helper(w, v, n, maxWeight, output);
}

// Brute force
int knapsack(int n, int *w, int *v, int max_w, int si){
    // Base case
    if(si == (n-1)){
        if(max_w >= w[si]) return v[si];
        else return 0;
    }

    // recursive calls
    // if size of first item is more than capacity
    if(max_w < w[si])
    return knapsack(n, w,v, max_w, si+1);
    // including the first item
    int a = knapsack(n, w, v, max_w-w[si], si+1) + v[si];
    // do not include first item
    int b = knapsack(n, w, v, max_w, si+1);
    return max(a,b);
}

int knapsack2(int* weight, int* value, int n, int maxWeight){
    // Base case
    if(n==0 or maxWeight==0) return 0;

    if(weight[0]>maxWeight) return knapsack2(weight+1, value+1, n-1 , maxWeight);

    // recursive calls
    int x = knapsack2(weight+1, value+1, n-1, maxWeight-weight[0]) + value[0];
    int y = knapsack2(weight+1, value+1, n-1, maxWeight);
    return max(x,y);

}

int main(){
    int n; cin >> n;
    int *w = new int[n];
    int *v = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int max_w; cin >> max_w;
    cout << knapsack(n, w, v, max_w, 0) << endl;
    cout << knapsack2(w, v, n, max_w) << endl;
    cout << knapsack_mem(w, v, n, max_w) << endl;
    cout << knapsack_DP(w, v, n, max_w) << endl;
}