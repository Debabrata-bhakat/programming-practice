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
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL); 
    int t;
    cin >> t;
    // t=1;
    while(t--) solve();
}

vector<double> bucket_sort(vector<double> arr, int n, int buckets){
	double min_el=arr[0],max_el=arr[0];
	for (int i = 0; i < n; ++i)
	{
		min_el = min(min_el,arr[i]), max_el = max(max_el,arr[i]);
	}
	double range = (max_el - min_el)/(buckets*1.0);
	vector<double> holes[buckets+1];
	cout << range << " " << min_el << " " << max_el << " alskdjf\n";
	for (int i = 0; i < n; ++i)
	{
		int bi = (int)((arr[i] - min_el)/range);
		holes[bi].push_back(arr[i]);
	}
	for (int i = 0; i < buckets+1; ++i)
	{
		sort(holes[i].begin(), holes[i].end());
	}
	vector<double> res;
	for (int i = 0; i < buckets+1; ++i)
	{
		for (int j = 0; j < holes[i].size(); ++j)
		{
			res.push_back(holes[i][j]);
		}
	}
	return res;
}

void solve(){
	int n;cin>>n; 
	vector<double> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	vector<double> res = bucket_sort(arr,n,5);
	for (int i = 0; i < n; ++i)
	{
		cout << res[i] << " ";
	}

}