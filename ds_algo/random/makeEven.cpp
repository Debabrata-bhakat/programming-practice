// https://codeforces.com/contest/1611/problem/0
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
    int n; cin >> n;
    // if it is even
    if(n%2==0){
        cout << "0\n";
        return;
    }
    vector<int> num;
    int temp = n;
    while(temp>0){
        num.push_back(temp%10);
        temp = temp/10;
    }
    // if first digit is even
    if(num[num.size()-1]%2==0){
        cout << "1\n";
        return;
    }
    for (int i = 0; i < num.size(); i++)
    {
        if(num[i]%2==0){
            cout << "2\n";
            return;
        }
    }
    cout << "-1\n";
}
