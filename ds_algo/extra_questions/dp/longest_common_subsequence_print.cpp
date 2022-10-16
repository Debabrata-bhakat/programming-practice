#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int ind1, int ind2){
	// base case
	if(ind1<0 or ind2<0) return 0;
	// last chars do not match
	if(s1[ind1]!=s2[ind2]) return max(lcs(s1,s2,ind1-1,ind2),lcs(s1,s2,ind1,ind2-1));
	else return 1+lcs(s1,s2,ind1-1,ind2-1);
}

int lcs_dp(string str1, string str2){
    int n = str1.length(),m=str2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=0;j<=m;j++) dp[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int i=n,j=m;
    string res="";
    while(i>0 and j>0){
    	if(str1[i-1]==str2[j-1]){
    		res = str1[i-1] + res;
    		i--;j--;

    	}else if(dp[i-1][j]>dp[i][j-1]){
    		i--;

    	}else{
    		j--;
    	}
    }
    cout << res << endl;
    return dp[n][m];
}

int main(){
	string s1,s2;
	cin>>s1>>s2;
	int l1=s1.length(),l2=s2.length();
	cout << lcs_dp(s1,s2);

}