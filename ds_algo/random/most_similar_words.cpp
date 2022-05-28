// https://codeforces.com/contest/1676/problem/C
#include <bits/stdc++.h>
#define ull unsigned long long 
using lli = long long int;
using namespace std;
int mod = 1e9+7;
void solve();
// calculate a^b mod 10^9+7
lli binary_exponentiation(lli a, lli b,  lli mod){
	lli ans=1;
	while(b>0){
		if(b%2==1){
			ans = (ans*a) % mod;
		}
		a = (a*a) %mod;
		b/=2;
	}
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    cin >> t;
    // t=1;
    while(t--) solve();
}

int distance(string s1, string s2){
	int n = s1.length();
	char c1[n + 1];
    strcpy(c1, s1.c_str());
    char c2[n + 1];
    strcpy(c2, s2.c_str());
    int res=0;
    for (int i = 0; i < n; ++i)
    {
    	res += abs(c1[i]-c2[i]);
    }
    return res;
}

void solve(){
	int n,m;cin>>n>>m;
	vector<string> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int res = 1e9;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			res = min(res,distance(arr[i],arr[j]));
		}
	}
	cout << res << endl;
}