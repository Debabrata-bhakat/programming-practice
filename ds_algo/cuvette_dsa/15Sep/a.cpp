#include <bits/stdc++.h>
using namespace std;


void rotate(vector<vector<int>>& matrix) {
    // Transpose
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i; j < matrix.size(); j++)
        {
            int temp = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size()/2; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrix.size()-1-j];
            matrix[i][matrix.size()-1-j] = temp;
        }
        
    }
    
}

int main(){
    vector<vector<int>> vect
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    rotate(vect);
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect.size(); j++)
        {
            cout << vect[i][j] << " ";
        }
        cout << '\n';
    }
}