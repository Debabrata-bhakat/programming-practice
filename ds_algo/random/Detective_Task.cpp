// https://codeforces.com/contest/1675/problem/C
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
	// int n;cin>>n;
	string s;cin>>s;
	int n = s.size();
	char char_array[n + 1];
    strcpy(char_array, s.c_str());
    int last_one=0, first_zero=n-1;
    for (int i = 0; i < n; ++i)
    {
    	// cout << i << endl;
    	if(char_array[i] == '0'){
    		// cout << i << endl;
    		first_zero=i; break;
    	}
    }
    for (int i = n-1; i >=0 ; --i)
    {
    	if(char_array[i] == '1'){
    		// cout << i << endl;
    		last_one = i; break;
    	}
    }
    // cout << first_zero << " " << last_one << endl;
    int ans = first_zero - last_one+1;
    cout << ans << endl;
}