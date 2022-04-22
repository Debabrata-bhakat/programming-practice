#include <iostream>
using namespace std;

// Dynamic programming
int lcs3(string s, string t){
    // Initialise the array
    int m = s.size();
    int n = t.size();
    int** output = new int*[m+1];
    for(int i = 0; i < (m+1); ++i)
        output[i] = new int[n+1];
    
    // Fill the first row and first column with zeroes
    for (int i = 0; i < m+1; i++)
    {
        output[i][0] = 0;
    }
    for (int i = 0; i < n+1; i++)
    {
        output[0][i] = 0;
    }
    
    // Start filling out the remaining array
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            char c1 = s[m - i];
            char c2 = t[n - j];
            // if the two characters are same
            if(c1==c2){
                output[i][j] = 1 + output[i-1][j-1];
            }else{
                output[i][j] = max( output[i-1][j], max( output[i][j-1], output[i-1][j-1] ) );
            }
        }
    }
    return output[m][n];
}

// Memoization
int lcs2(string s, string t, int **output){
    int m = s.size();
    int n = t.size();
    // Base case
    if(s.size()==0 or t.size()==0) return 0;

    // Check if answer already exists
    if(output[m][n] != -1){
        return output[m][n];
    }

    int ans;
    // Recursive calls
    if(s[0] == t[0]){
        ans = 1 + lcs2(s.substr(1), t.substr(1), output);
    }else{
        int a = lcs2(s.substr(1), t, output);
        int b = lcs2(s, t.substr(1), output);
        int c = lcs2(s.substr(1), t.substr(1), output);
        ans = max(a, max(b,c));
    }

    // Save your calculation
    output[m][n] = ans;

    // Return ans 
    return ans;
}

int lcs2(string s, string t){
    int m = s.size() + 1;
    int n = t.size() + 1;
    int** output = new int*[m];
    for(int i = 0; i < (m); ++i)
        output[i] = new int[n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            output[i][j] = -1;
        }
    }
    
    return lcs2(s,t,output);
}

// Brute force
int lcs(string s, string t){
    // Base case
    if(s.size()==0 or t.size()==0) return 0;
    // Recursive calls
    if(s[0] == t[0]){
        return 1 + lcs(s.substr(1), t.substr(1));
    }else{
        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        int c = lcs(s.substr(1), t.substr(1));
        return max(a, max(b,c));
    }
}

int main(){
    string s,t; cin >> s >> t;
    cout << lcs(s,t) << endl;
    cout << lcs2(s,t) << endl;
    cout << lcs3(s,t) << endl;
}