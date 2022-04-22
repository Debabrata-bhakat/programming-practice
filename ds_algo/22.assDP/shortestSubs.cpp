#include <iostream>
using namespace std;

int solve_DP(string s, string t){
    int n = s.size()+1;
    int m = t.size()+1;
    int** dp = new int*[n];
    for(int i = 0; i < (n); ++i)
        dp[i] = new int[m];
    
    // fill the first row
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = 1;
    }
    // fill the first column
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = INT16_MAX;
    }
    
    // fill the remaining
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            // find the current character
            char c = s[s.size()-i];
            int k;
            for (k = t.size()-j; k < t.size(); k++)
            {
                if(c==t[k]) break;
            }
            // if not found
            if(k==t.size()){
                dp[i][j] = 1;
                continue;
            }
            int x = dp[i-1][j-k-1] + 1;
            int y = dp[i-1][j];
            dp[i][j] = min(x,y);
        }
    }
    return dp[s.size()][t.size()];
}

int solve_mem(int** dp, string s, string t){
    // base case
    if(s.length()==0) return INT16_MAX;
    if(t.length()==0) return 1;

    // check if the answer exists
    if(dp[s.length()][t.length()] != -1) return dp[s.length()][t.length()];
    
    // find the current character
    char c = s[0];
    int i;
    for (i = 0; i < t.size(); i++)
    {
        if(c==t[i]) break;
    }
    // if not found
    if(i==t.size()) return 1;
    // if found
    // including the first character
    int x = solve_mem(dp, s.substr(1), t.substr(i+1)) + 1;
    // not including the first character
    int y = solve_mem(dp, s.substr(1), t);
    dp[s.length()][t.length()] = min(x,y);
    return dp[s.length()][t.length()];
}

int solve_mem(string s, string t){
    int n = s.size()+1;
    int m = t.size()+1;
    int** dp = new int*[n];
    for(int i = 0; i < (n); ++i)
        dp[i] = new int[m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = -1;
        }
        
    }
    return solve_mem(dp, s, t);   
}

int solve(string s, string t){
    // base case
    if(s.size()==0) return INT16_MAX;
    if(t.size()==0) return 1;

    // find the current character
    char c = s[0];
    int i;
    for (i = 0; i < t.size(); i++)
    {
        if(c==t[i]) break;
    }
    // if not found
    if(i==t.size()) return 1;
    // if found
    // including the first character
    int x = solve(s.substr(1), t.substr(i+1)) + 1;
    // not including the first character
    int y = solve(s.substr(1), t);
    return min(x,y);
}

int main(){
    string s, t; cin >> s >> t;
    cout << solve(s,t) << endl;
    cout << solve_mem(s,t) << endl;
    cout << solve_DP(s,t) << endl;
}