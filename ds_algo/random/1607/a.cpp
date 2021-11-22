#include <bits/stdc++.h>
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

// https://codeforces.com/problemset/problem/1607/E

void solve(){
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    int x_max = 0, x_min = 0, y_min = 0, y_max = 0;
    int x_curr = 0, y_curr = 0;
    int x_left = 1 - x_min;
    int x_right = m - x_max;
    int y_top = 1 + y_max;
    int y_bot = n + y_min;

    for (int i = 0; i < s.length(); i++)
    {

        char ch = s[i];
        if(ch=='R') x_curr++;
        else if(ch=='L') x_curr--;
        else if(ch=='U') y_curr++;
        else y_curr--;

        if(x_max < x_curr) x_max = x_curr;
        if(x_min > x_curr) x_min = x_curr;
        if(y_min > y_curr) y_min = y_curr;
        if(y_max < y_curr) y_max = y_curr;

        if(1 - x_min  > m - x_max or 1 - y_min > n - y_max){
            cout << y_top << " " << x_left << endl;
            return;
        }

        x_left = 1 - x_min;
        x_right = m - x_max;
        y_top = 1 + y_max;
        y_bot = n + y_min;
    }
    cout << y_top << " " << x_left << endl;

}