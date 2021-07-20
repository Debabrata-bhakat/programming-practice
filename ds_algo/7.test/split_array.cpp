#include <iostream>
using namespace std;


int split(int *arr, int size){
    // If size is odd then return false
    if(size%2 == 1) return 0;
    int *div_5 = new int[size];
    int *div_3 = new int[size];
    int *rem = new int[size];
    int in_5 = 0, in_3 = 0, in_rem = 0,sum_3 = 0,sum_5 = 0,sum_rem = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]%5 == 0)
        {
            div_5[in_5++] = arr[i];       
            sum_5 += arr[i];
        }
        else if (arr[i]%3 == 0 and arr[i]%5!=0)
        {
            div_3[in_3++] = arr[i];
            sum_3 += arr[i];
        }
        else{
            rem[in_rem++] = arr[i];
            sum_rem += arr[i];
        }
        
    }
    

}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << split(arr,n) << endl;    
}