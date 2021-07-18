#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(int *a1, int size1, int *a2, int size2, int *a3){
    sort(a1,a1+size1);
    sort(a2,a2+size2);
    int c = 0;
    //Merge approach
    int i = 0, j = 0;
    while (i<size1 and j<size2)
    {
        if(a1[i] == a2[j]){
            a3[c++] = a1[i];
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    return c;
}

int main(){
    int n,m;
    cin >> n;
    int *arr_1 = new int [n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr_1[i];
    }
    cin >> m;
    int *arr_2 = new int [m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr_2[i];
    }
    int inter_size = max(m,n);
    int *arr_3 = new int[inter_size];
    int res = solve(arr_1, n, arr_2,m,arr_3);
    for (int i = 0; i < res; i++)
    {
        cout << arr_3[i] << " ";
    }
    cout << endl;
    
}