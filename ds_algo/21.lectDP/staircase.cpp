#include <iostream>
using namespace std;

// Dynamic programming
int staircase3(int n){
    int *ans = new int[n+1];
    // precomputer results
    ans[0]=0, ans[1]=1, ans[2]=2, ans[3]=4;
    for (int i = 4; i <= n; i++)
    {
        ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
    }
    return ans[n];
}

// Memoization
int staircase2_helper(int n, int *ans){
    // Base case
    if(n<1) return 0;
    // check if answer already exists
    if(ans[n]!=-1) return ans[n];

    // else calculate the answer
    // store the answer for future use
    ans[n] = staircase2_helper(n-1, ans) + staircase2_helper(n-2, ans) + staircase2_helper(n-3, ans);
    return ans[n];
}
int staircase2(int n){
    int *ans = new int[n+1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    // precomputer results
    ans[0]=0, ans[1]=1, ans[2]=2, ans[3]=4;
    return staircase2_helper(n, ans);
}

// Brute force
int staircase(int n){
    // Base case
    if(n<1) return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;
    // small calculation
    return staircase(n-1) + staircase(n-2) + staircase(n-3);
}

int main(){
    // int n; cin >> n;
    for (int i = 1; i < 11; i++)
    {
        cout << staircase3(i) << endl;
    }
    
}