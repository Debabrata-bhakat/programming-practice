#include <bits/stdc++.h>
using namespace std;

string lps(string a){
	int n=a.length();
	vector<vector<bool>> dp(n,vector<bool>(n,0));
	int pos_i=0,pos_j=0,max_a=0;
	for(int i=0;i<n;i++) dp[i][i]=true;
	for(int i=1;i<n;i++){
		for(int j=i;j<n;j++){
			// dp[j-i][j]
			// cout << j-i << "  " << j << endl;
			if(a[j-i] == a[j]){
				if(i==1) dp[j-i][j]=true;
				else if(dp[j-i+1][j-1]) dp[j-i][j] = true;
				else dp[j-i][j] = false;
				if(max_a<i and dp[j-i][j]){
					max_a = i;
					pos_i=j-i;pos_j=j;
				}
			}else{
				dp[j-i][j]=false;
			}
		}
	}	
	// find max
	// for(int i=0;i<n;i++){
	// 	for(int j=i;j<n;j++){
	// 		if(max_a<dp[i][j]){
	// 			pos_i=i,pos_j=j,max_a=dp[i][j];
	// 		}
	// 	}
	// }
	cout << max_a << endl;
	return a.substr(pos_i,pos_j-pos_i+1);
}


int main(){
	string a;
	cin>>a;
	cout << lps(a) << endl;
}