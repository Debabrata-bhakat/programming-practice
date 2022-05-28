#include <bits/stdc++.h>
#define ull unsigned long long 
using lli = long long int;
using namespace std;
int mod = 1e9+7;
void solve();
int freq[100100];
int  cntDistinct = 0;
void insert(int x){
	if(freq[x]==0) cntDistinct++;
	freq[x]++;
}
void remove(int x){
	freq[x]--;
	if(freq[x]==0) cntDistinct--;
}
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
	int n,k;cin>>n>>k;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int head=-1,tail=0,ans=0;
	while(tail<n){
		while(head+1<n and ( (cntDistinct<=k and freq[arr[head+1]]>0) or (cntDistinct<k and freq[arr[head+1]]==0) ) ){
			head++;
			insert(arr[head]);
		}
		ans +=(head-tail+1);
		if(head>=tail){
			remove(arr[tail]);
			tail++;
		}else{
			tail++;
			head = tail-1;
		}
	}
	cout << ans << endl;
}