#include <iostream>
#include <cmath>
using namespace std;

// Dynamic programming approach
int numTrees3(int n){
    int *ans = new int[n+1];
    // store the default answers
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 3;

    int mod = (int)(pow(10,9)) + 7;
    for (int i = 3; i <= n; i++)
    {
        int a = ans[i-1];
        int b = ans[i-2];
        int temp1 = (int)( ((long)(a) * a) % mod );
        int temp2 = (int)((2 * (long)(a) * b) % mod);
        ans[i] = (temp1 + temp2) % mod;
    }
    return ans[n];
}

int numTrees2_helper(int n, int *ans){
    // check if answer already exists
    if(ans[n]!=-1) return ans[n];

    // else do the calculation
    int mod = (int)(pow(10,9)) +7;

    int a = numTrees2_helper(n-1, ans);
    int b = numTrees2_helper(n-2, ans);

    int temp1 = (int)( ((long)(a) * a) % mod );
    int temp2 = (int)((2 * (long)(a) * b) % mod);
    // save the answer for future use
    ans[n] = (temp1 + temp2) % mod;
    // return the answer
    return ans[n];

}

int numTrees2(int n){
    int *ans = new int[n+1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 3;
    return numTrees2_helper(n, ans);
}


// Brute force
int numTrees(int n){
    // Base case
    if(n==1) return 1;
    if(n==2) return 3;

    int mod = (int)(pow(10,9)) +7;

    // small calculation
    int a = numTrees(n-1);
    int b = numTrees(n-2);

    int temp1 = (int)( ((long)(a) * a) % mod );
    int temp2 = (int)((2 * (long)(a) * b) % mod);
    return (temp1 + temp2) % mod;
}

int main(){
    int n; cin >> n;
    cout << numTrees(n) << endl;
    cout << numTrees2(n) << endl;
    cout << numTrees3(n) << endl;
}