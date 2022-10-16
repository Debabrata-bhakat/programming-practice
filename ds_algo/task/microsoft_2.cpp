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

int gcd(int a, int b){
	if(a==0 or b==0) return a^b;
	return __gcd(a,b);
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

int solution(string & s) {
    int red_count = 0;
    // count number of Rs in the string
    for (char c : s) {
        if (c == 'R') ++red_count;
    }
    // Init indexes to the ends of the string and the result 
    int left = 0, right = s.size() - 1, result = 0;
    // moving from the ends to the middle
    while (left < right) {
        // if we meet pair of Rs on the ends
        if (s[left] == 'R' && s[right] == 'R') {
            // add to the result number of Ws between of these Rs
            red_count -= 2;
            result += right - left - 1 - red_count;
            // and shrink the processing window
            ++left;
            --right;
        } 
        // pass all Ws we meet
        else if (s[left] != 'R') {
            ++left;
        } 
        else {
            --right;
        }
    }
    return result;
}

void solve(){
	string s; cin>>s;	
	cout << solution(s) << endl;
}