// https://codeforces.com/contest/1678/problem/B1
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
	int n;cin>>n;
	int arr[n];
	string s;cin>>s;
	char char_array[n + 1];
    strcpy(char_array, s.c_str());
    for (int i = 0; i < n; ++i)
    {
    	if(char_array[i] == '1') arr[i] = 1;
    	else arr[i]=0;
    }
    // for (int i = 0; i < n; ++i)
    // {
    // 	cout << arr[i] << " " << endl;
    // }
    int prev = arr[0],curr=1;
    vector<pair<int,int>> parity;
    for (int i = 1; i < n; ++i)
    {
    	if(prev==arr[i]) curr++;
    	else{
    		pair<int,int> temp(curr,arr[i-1]);
    		parity.push_back(temp);
    		prev = arr[i];
    		curr = 1;
    	}
    }
    pair<int,int> temp(curr,arr[n-1]);
    parity.push_back(temp);
    int head=-1, tail=-1,head_ind=-1,tail_ind=-1,ans=0;
    for (int i = 0; i < parity.size(); ++i)
    {
    	if(parity[i].first%2==0) continue;
    	if(tail==-1){
    		head = parity[i].second;
    		tail = parity[i].second;
    		head_ind = i; tail_ind=i;
    	}else{
    		// if(tail == parity[i].second){
    		// 	ans += 2;
    		// }else{
    		// 	ans += (i-tail_ind);
    		// }
    		ans += (i-tail_ind);
    		head=-1, tail=-1,head_ind=-1,tail_ind=-1;
    	}
    }
    cout << ans << endl;
}