#include <bits/stdc++.h>
#define ull unsigned long long 
using lli = long long int;
using namespace std;

int cntDistinct = 0;
int freq[100100];

void insert(int x){
	freq[x]++;
	if(freq[x]==1){
		cntDistinct++;
	}
}
void remove(int x){
	freq[x]--;
	if (freq[x]==0)
	{
		cntDistinct--;
	}
}
int n,k;
vector<int> arr;
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
	cin>>n>>k;
	arr.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int ans=0, head=-1,tail=0;
	while(tail<n){
		while(head+1<n && ( (cntDistinct<k && freq[arr[head+1]]==0) || (cntDistinct<=k&&freq[arr[head+1]]>0) ) ){
			head++;
			insert(arr[head]);
		}
		ans = max(ans,head-tail+1);
		// for counting number of subarryas 
		// ans += (head-tail+1);
		if(head<tail){
			tail++;
			head = tail-1;
		}else{
			remove(arr[tail]);
			tail++;
		}
	}
	cout << ans << endl;
}