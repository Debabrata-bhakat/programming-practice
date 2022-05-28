// https://codeforces.com/contest/1676/problem/A
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

void solve(){
	string s;cin>>s;
	int n = s.length();
 
    // declaring character array
    char char_array[n + 1];
 
    // copying the contents of the
    // string to char array
    strcpy(char_array, s.c_str());
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
    	arr[i] = char_array[i] - '0';
    }
    int sum1=0;
    for (int i = 0; i < 3; ++i)
    {	
    	sum1+=arr[i];
    }
    int sum2=0;
    for (int i = 3; i < 6; ++i)
    {
    	sum2+=arr[i];
    }
    if(sum1==sum2) cout << "YES\n";
    else cout << "NO\n";
}