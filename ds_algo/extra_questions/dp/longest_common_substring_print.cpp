#include <bits/stdc++.h>
using namespace std;

string lcs_dp(string s1, string s2){
	int n = s1.length(),m=s2.length();
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=0;i<=n;i++) dp[i][0]=0;
	for(int j=0;j<=m;j++) dp[0][j]=0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j]=0;
			}
		}
	}
	// find max
	int pos_i=0,pos_j=0,max_a=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(dp[i][j]>max_a){
				pos_i=i;pos_j=j;max_a=dp[i][j];
			}
		}
	}
	string res="";
	while(pos_i>0 and pos_j>0 and dp[pos_i][pos_j]>0){
		res = s1[pos_i-1] + res;
		pos_i--;pos_j--;
	}
	return res;
}

int main(){
	string s1,s2;
	cin>>s1>>s2;
	cout << lcs_dp(s1,s2) << endl;
}