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

long long C(int n, int r) {
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
vector<int> getRow(int A) {
    vector<int> arr(A+1);
    for(int i=0;i<=A;i++){
        arr[i] = (int)(C(A,i));
        cout << arr[i] << endl;
    }
    return arr;
}

void solve(){
	int n;cin>>n;
	vector<int> arr = getRow(n);
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << arr[i] << endl;
	// }
}