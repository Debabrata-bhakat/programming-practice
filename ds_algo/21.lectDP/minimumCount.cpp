#include <iostream>
#include <cmath>
using namespace std;

// Dynamic programming approach
int minCount3(int n){
    int *ans = new int[n+1];
    // initialse answers to default values
    for (int i = 0; i <= n; i++)
    {
        ans[i] = i;
    }
    
    ans[0]=0, ans[1]=1, ans[2]=2, ans[3]=3;
    for (int i = 4; i <= n; i++)
    {
        int sq = sqrt(i);
        for (int j = 1; j <= sq; j++)
        {
            ans[i] = min(ans[i], ans[i-j*j]+1);
        }
    }
    return ans[n];
}


// Memoisation
int minCount2_helper(int n, int *ans){
    int sq = sqrt(n);
    // Base case : if n is a perfect square
    if(sq*sq==n){
        ans[n] = 1;
        return 1;
    }

    // check if answer already exists
    if(ans[n]!=-1) return ans[n];
    
    // else compute the answer
    int res = INT16_MAX;
    for (int i = 1; i <= sq; i++)
    {
        int smallOutput = minCount2_helper(n-i*i, ans);
        res = min(res, smallOutput);
    }
    res = res + 1;
    // store the result for future use
    ans[n] = res;
    // return the answer
    return ans[n];
}

int minCount2(int n){
    int *ans = new int[n+1];
    // intialise all answers to default
    for (int i = 0; i < n+1; i++)
    {
        ans[i] = -1;
    }
    return minCount2_helper(n, ans);
}

// Brute force
int minCount(int n){
    int sq = sqrt(n);
    // Base case : if n is a perfect square
    if(sq*sq==n) return 1;
    int ans = INT16_MAX;
    for (int i = 1; i <= sq; i++)
    {
        int smallOutput = minCount(n-i*i);
        ans = min(ans, smallOutput);
    }
    return ans+1;
}

int main(){
    int n; cin >> n;
    cout << minCount(n) << endl;
    cout << minCount2(n) << endl;
    cout << minCount3(n) << endl;
}