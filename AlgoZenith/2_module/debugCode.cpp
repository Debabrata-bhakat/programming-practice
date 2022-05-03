#include <bits/stdc++.h>
#define ull unsigned long long 
#define ll long long
using namespace std;



int bruteSolve(int n, int k, vector<int> v){
	vector<int> temp;
	for (int i = 1; i <= n; ++i)
	{
		temp.push_back(v[i]);
	}
	return *kth_element(temp.begin(),temp.begin()+k-1,temp.end());
}

int solve(int n, int k, vector<int> arr){
	sort(arr.begin()+1,arr.begin()+n);
	return arr[k];
}

void Generator(){
	vector<int> test = {0,1,3,4,2,9};
	int n = 5,k = 2;
	pr(n,k,)
}

// DEBUG
// 1. SOLVE


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    // cin >> t;
    t=1;
    while(t--) solve();
}

