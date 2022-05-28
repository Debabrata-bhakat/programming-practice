#include <bits/stdc++.h>
#define ull unsigned long long 
using lli = long long int;
using namespace std;
int mod = 1e9+7;
void insert(int x, int* freq, int& cntDistinct){
	freq[x]++;
	if(freq[x]==1) cntDistinct++;
}
void remove(int x, int* freq, int& cntDistinct){
	freq[x]--;
	if(freq[x]==0) cntDistinct--;
}
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
	int freq[100100];
	for (int i = 0; i < 100100; ++i)
	{
		freq[i]=0;
	}
	int cntDistinct=0;
	int n,d;cin>>n>>d;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int head = -1, tail=0, ans=1e9;
	while(tail<n-d+1){
		while(head+1<n and head+1-tail+1<=d){
			head++;
			insert(arr[head],freq,cntDistinct);
		}
		// cout << cntDistinct << " "<< tail << " " << head << endl;
		ans = min(ans,cntDistinct);
		if(tail<=head){
			remove(arr[tail],freq,cntDistinct);
			tail++;
		}else{
			tail++;
			head = tail-1;
		}
	}
	cout << ans << endl;
}