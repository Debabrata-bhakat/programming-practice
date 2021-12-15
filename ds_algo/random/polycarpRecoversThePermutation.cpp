// https://codeforces.com/contest/1611/problem/C
#include <bits/stdc++.h>
#define ull unsigned long long 
using namespace std;
void solve();
void solve2();
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
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int t; cin >> t;
        a.push_back(t);
    }
    if(a[0]!=n and a[n-1]!=n){
        cout << "-1\n";
        return;
    }
    if(a[0]==n) a.erase(a.begin());
    else a.erase(a.begin()+n-1);
    cout << n << " ";
    for (int i = n-2; i >=0 ; i--)
    {
        cout << a[i] << " ";
    }
    cout << '\n';
}

void solve3(){
    int n; cin >> n;
    int *a = new int[n];
    int si = 0,ei = n-1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if(a[0]!=n and a[n-1]!=n){
        cout << "-1\n";
        return;
    }
    vector<int> output;
    if(a[0]>a[n-1]){
        si = 1;
        output.push_back(a[0]);
    }else{
        ei = n-2;
        output.push_back(a[n-1]);
    }
    while(si<=ei){
        if(a[si]>a[ei]){
            output.insert(output.begin(),a[si]);
            if(a[si]>output[output.size()-1]){
                cout << "-1\n";
                return;
            }
            si++;
        }else{
            output.push_back(a[ei]);
            if(a[ei]>output[0]){
                cout << "-1\n";
                return;
            }
            ei--;
        }
    }
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << '\n';
}


void solve2(){
    int n; cin >> n;
    int *a = new int[n];
    int si = 0,ei = n-1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> output;
    if(a[0]>a[n-1]){
        si = 1;
        output.push_back(a[0]);
    }else{
        ei = n-2;
        output.push_back(a[n-1]);
    }
    while(si<=ei){
        if(a[si]>a[ei]){
            output.insert(output.begin(),a[si]);
            if(a[si]>output[output.size()-1]){
                cout << "-1\n";
                return;
            }
            si++;
        }else{
            output.push_back(a[ei]);
            if(a[ei]>output[0]){
                cout << "-1\n";
                return;
            }
            ei--;
        }
    }
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << '\n';
}