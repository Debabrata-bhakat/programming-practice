#include <iostream>
using namespace std;

int lis(int* a, int n){
    int* dp = new int[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = i; j >= 0; j--)
        {
            if(a[j] < a[i]) dp[i] = max( dp[i], dp[j]+1 );
        }
    }
    int ans = dp[0];
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(){
    int n; cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << lis(a, n) << endl;
    delete [] a;
}