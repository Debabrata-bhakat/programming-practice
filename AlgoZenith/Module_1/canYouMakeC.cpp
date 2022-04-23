#include <bits/stdc++.h>
#define ull unsigned long long 
#define ll long long
using namespace std;
void solve();
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    ull t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}

void solve(){
	int a,b,c;cin>>a>>b>>c;
	int g = __gcd(a,b);
	if(c%g==0) cout << "Yes\n";
	else cout << "No\n";
}