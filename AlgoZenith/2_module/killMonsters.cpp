#include <bits/stdc++.h>
#define ull unsigned long long 
#define ll long long
using namespace std;
void solve();

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    cin >> t;
    // t=1;
    while(t--) solve();
}

bool cmp(pair<int,int> a, pair<int,int> b){
	return ((a.first - a.second) > (b.first - b.second));
}

void solve(){
	int n;cin>> n;
	vector<pair<int,int>> a;
	for (int i = 0; i < n; ++i)
	{
		int temp1,temp2;cin>>temp1>>temp2;
		pair<int,int> temp(temp1,temp2);
		a.push_back(temp);
	}
	sort(a.begin(),a.end(),cmp);
	int max = a[0].first,curr = a[0].first - a[0].second;
	for (int i = 1; i < n; ++i)
	{
		int temp = a[i].first - curr;
		if(temp>0) max += temp;
		curr = a[i].first - a[i].second;
	}
	cout << max << endl;
}