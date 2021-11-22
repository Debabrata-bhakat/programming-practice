// https://codeforces.com/contest/1612/problem/B
#include <bits/stdc++.h>
#define ull unsigned long long 
using namespace std;
void solve();
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}

void solve(){
    int n,a,b;
    cin >> n >> a >> b;
    if((b<=n/2 and a<=n/2) or ( a>n/2 and b>n/2 )){
        cout << "-1\n";
        return;
    }
    if(b>=n/2 and a<=n/2+1){

    }else{
        cout << "-1\n";
        return;
    }
    vector<int> arr_1;
    arr_1.push_back(a);
    vector<int> arr_2;
    arr_2.push_back(b);
    // for (int i = n/2+1; i < n+1; i++)
    // {
    //     if(i!=b and i!=a) arr_1.push_back(i);
    // }
    // for (int i = 1; i < n/2+1; i++)
    // {
    //     if(i!=a and i!=b) arr_2.push_back(i);
    // }
    int i = 0;
    while(arr_2.size()!=n/2){
        i++;
        if(i!=b and i!=a) arr_2.push_back(i);
    }
    while(arr_1.size()!=n/2){
        i++;
        if(i!=b and i!=a) arr_1.push_back(i);
    }
    for (int i = 0; i < arr_1.size(); i++)
    {
        cout << arr_1[i] << " ";
    }
    for (int i = 0; i < arr_2.size(); i++)
    {
        cout << arr_2[i] << " ";
    }
    cout << '\n';
}