#include <bits/stdc++.h>
using namespace std;
void solve();
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    t=1;
    while(t--)
    {
        solve();
    }
}
int checkTriangle(int a, int b, int c){
    if(a+b > c ) return 1;
    else return 0;
}

void solve(){
    int n;
    cin >> n;
    vector<int> sides;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        sides.push_back(temp);
    }
    sort(sides.begin(), sides.end());
    for (int i = 0; i < n-2; i++)
    {
        if(checkTriangle(sides[i],sides[i+1], sides[i+2])){
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}
