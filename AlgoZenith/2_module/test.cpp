#include <bits/stdc++.h>
#define ull unsigned long long 
#define ll long long
using namespace std;
void solve();

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    // cin >> t;
    t=1;
    while(t--) solve();
}

void test(vector<int> &a){
    a[0] = 10;
}

void solve(){
    vector<int> a{1,2,3,4};
    test(a);
    for (int i = 0; i < 4; ++i)
    {
        cout << a[i] << endl;
    }
}