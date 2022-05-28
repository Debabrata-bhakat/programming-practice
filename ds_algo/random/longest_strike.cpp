// https://codeforces.com/contest/1676/problem/F
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
	int n,k;cin>>n>>k;
	map<int,int> m;
	for (int i = 0; i < n; ++i)
	{
		int temp;cin>>temp;
		m[temp]++;
	}
	vector<pair<int,int>> arr;
	for(auto i : m){
		pair<int,int> temp (i.first,i.second);
		arr.push_back(temp);
		// cout << i.first << " " << i.second << endl;
	}
	int head=-1,tail=0,ansr=-1,ansl=-1,ans=0;
	n=arr.size();
	while(tail<n){
		while(head+1<n and arr[head+1].second>=k and ( head+1==tail or arr[head+1].first-1==arr[head].first ) ){
			head++;
			if(arr[head].first-arr[tail].first >= ans) {
				ansr = arr[head].first, ansl = arr[tail].first, ans = ansr-ansl; 
			} 
		}
		if(head>=tail){
			tail++;
		}else{
			tail++;
			head = tail-1;
		}
	}
	if(ansr==-1 or ansl==-1) cout << "-1\n";
	else cout << ansl << " " << ansr << endl;
}