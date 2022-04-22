#include <iostream>
#include <cmath>
using namespace std;

int apw(int a, int* arr, int n){
    // Base case
    if(a==0) return 1;
    // Base case
    if(a<0 or n<=0) return 0;
    // recursive calls
    int x = apw(a-arr[0], arr+1, n-1);
    int y = apw(a, arr+1, n-1);
    return x+y;
}

int main(){
    int a, b; cin >> a >> b;
    int n = sqrt(a);
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int)pow(i+1,b);
    }
    cout << apw(a, arr, n) << endl;
}