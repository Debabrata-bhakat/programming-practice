// https://codeforces.com/problemset/problem/1594/C
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
    // solve();
}

void solve(){
    int size;
    cin>>size;
    char c;
    cin >> c;
    string s; cin >> s; s = " " + s;
    int flag = 0;
    // if all are same
    for (int i = 1; i <= size; i++)
    {
        if(s[i]!=c) {
            flag = 1;
        } 
    }
    if (flag==0){
        cout << "0\n";
        return;
    }
    // check if it is possible with one operation
    for (int i = 2; i <= size; i++)
    {
        flag = 0;
        for (int j = i; j <= size; j=j+i)
        {
            if(j%i==0 and s[j]!=c){
                flag = 1;
                break;
            }
        }
        if(flag==0){
            cout << "1\n" << i << '\n';
            return;
        }
    }
    cout << "2\n" << size << " " << size-1 << '\n';
}