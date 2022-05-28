#include <bits/stdc++.h>
#define ull unsigned long long 
using lli = long long int;
using namespace std;
int mod = 1e9+7;
void insert(int*freq, int x, int& cntDistinct){
	freq[x]++;
	if(freq[x]==1) cntDistinct++;
}
void remove(int* freq, int x, int& cntDistinct){
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
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL); 
    int t;
    cin >> t;
    // t=1;
    while(t--) solve();
}

void solve(){
	int freq[1001];
	for (int i = 0; i < 1001; ++i)
	{
		freq[i]=0;
	}
	int n,cntDistinct=0;cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		insert(freq,arr[i],cntDistinct);
		// cout << i << endl;
	}
	int temp_cnt = cntDistinct;
	cntDistinct=0;
	for (int i = 0; i < 1001; ++i)
	{
		freq[i]=0;
	}
	int head=-1,tail=0,ans=1e9;
	while(tail<n){
		while(head+1<n and (cntDistinct<temp_cnt)){
			head++;
			insert(freq,arr[head],cntDistinct);
		}
		if(cntDistinct == temp_cnt)
		ans = min(ans,head-tail+1);
		if(head>=tail){
			remove(freq,arr[tail],cntDistinct);
			tail++;
		}else{
			tail++;
			head = tail-1;
		}
	}
	cout << ans << endl;
}