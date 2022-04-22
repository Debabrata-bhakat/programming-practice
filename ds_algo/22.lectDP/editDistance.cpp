#include <iostream>
using namespace std;

// Dynamic programming approach
int editDistance_DP(string s1, string s2){
    int m = s1.size(), n = s2.size();
    int** output = new int*[m+1];
    for(int i = 0; i < (m+1); ++i)
        output[i] = new int[n+1];
    // fill the first row
    for (int i = 0; i < n+1; i++)
    {
        output[0][i] = i;
    }
    // fill the first column
    for (int i = 0; i < m+1; i++)
    {
        output[i][0] = i;
    }
    // fill the remaining array
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            char c1 = s1[m-i];
            char c2 = s2[n-j];
            // check the first characters
            if(c1 == c2) output[i][j] = output[i-1][j-1];
            else{
                int x = output[i-1][j] + 1;
                int y = output[i][j-1] + 1;
                int z = output[i-1][j-1] + 1;
                output[i][j] = min(x, min(y,z));
            }
        }
    }
    return output[m][n];
}

// Memoisation
int editDistance_mem(string s1, string s2, int ** output){
    int m = s1.size(), n = s2.size();
    // if either one is empty
    if(s1.size() == 0 or s2.size() == 0) return max(m, n);

    // check if answer already exists   
    if(output[m][n] != -1) return output[m][n];

    // recursive call
    if(s1[0] == s2[0]) output[m][n] = editDistance_mem(s1.substr(1), s2.substr(1), output);
    else{
        // insert
        int x = editDistance_mem(s1.substr(1), s2, output) + 1;
        // delete
        int y = editDistance_mem(s1, s2.substr(1), output) + 1;
        // replace
        int z = editDistance_mem(s1.substr(1), s2.substr(1), output) + 1;
        output[m][n] = min(x, min(y,z));
    }
    return output[m][n];
}

int editDistance_mem(string s1, string s2){
    int m = s1.size(), n = s2.size();
    int** output = new int*[m+1];
    for(int i = 0; i < (m+1); ++i)
        output[i] = new int[n+1];
    for (int i = 0; i < m+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            output[i][j] = -1;
        }
    }
    return editDistance_mem(s1, s2, output);
}

// brute force
int editDistance(string s1, string s2){
    // if either one is empty
    if(s1.size() == 0 or s2.size() == 0) return max(s1.size(), s2.size());

    // recursive call
    if(s1[0] == s2[0]) return editDistance(s1.substr(1), s2.substr(1));
    // insert
    int x = editDistance(s1.substr(1), s2) + 1;
    // delete
    int y = editDistance(s1, s2.substr(1)) + 1;
    // replace
    int z = editDistance(s1.substr(1), s2.substr(1)) + 1;
    return min(x, min(y,z));
}

int main(){
    // string s1, s2; cin >> s1 >> s2;
    string s1 = "abcdfabcdfbcdf";
    string s2 = "afdiafdafafdaf";
    cout << editDistance_mem(s1, s2) << endl;
    cout << editDistance_DP(s1, s2) << endl;
    cout << editDistance(s1, s2) << endl;
}