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
	lli n,k,d;
	lli arr[n];
	lli preFix[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[n];
		preFix[i] = arr[i];
		if(i) preFix[i] += arr[i-1];
	}
	int head = -1, tail=0;
	multiset<lli> mt;
	int oddCnt = 0;
	lli best = -1e18;
	while(tail<n){
		while(head+1<n && ( ( oddCnt<k and arr[head+1]%2 ) || ( oddCnt<=k && arr[head+1]==0 ) )){
			head++;
			if(arr[head]%2) oddCnt++;
			mt.insert(preFix[head]);
		}
		lli temp = d + (tail>0?preFix[tail-1]:0);
		auto it = mt.upper_bound(temp);
		if(it!=mt.begin()){
			it--;
			best = max(best, *it - (tail>0?preFix[tail-1]:0));
		}
		if(head<tail){
			tail++;
			head = tail-1;
		}else{
			if(arr[tail]%2){
				oddCnt--;
			}
			mt.erase(mt.find(preFix[tail]));
			tail++;
		}
	}
	if(best == -1e18){
		cout << "IMPOSSIBLE\n";
	}else{
		cout << best << endl;
	}
}