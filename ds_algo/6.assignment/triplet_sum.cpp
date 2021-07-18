#include<bits/stdc++.h>
using namespace std;
void solve();
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}

int pair_sum(int *arr, int size, int sum){
    sort(arr, arr+size);
    int count = 0;
    int in = 0, last = size - 1;
    int last_flag = 0;
    while(in<last){
        if(arr[in] + arr[last] == sum){
            last_flag = last;
            while (last>in and arr[in] + arr[last] == sum)
            {
                count++;
                last --;
            }
            last = last_flag;
            in++;
            
        }
        else if(arr[in] + arr[last] > sum){
            last --;
        }
        else{
            in++;
        }
    }
    return count;
}

int trip_sum(int *arr, int size, int sum){
    int count = 0;
    for (int i = 0; i < size-2; i++)
    {
        int curr = arr[i];
        int res = pair_sum(arr+i+1,size-i-1,sum-curr);
        count += res;
    }
    return count;
}

void solve(){
    int n, sum;
    cin >> n;
    int *arr = new int [n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> sum;
    cout << trip_sum(arr,n,sum) << '\n';
}