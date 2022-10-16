#include <bits/stdc++.h>
using namespace std;

bool is_valid(string s){
	// check length
	if(s[0]=='0') return false;
	int num = stoi(s);
	return num<=255;
}

void helper(string s, int dots, int i, string ans, vector<string>& res){
	// base case
	// success
	if(dots==4 and i==s.length()){
		res.push_back(ans.substr(0,ans.length()-1));
		return;
	}
	// unsuccessful base case
	if(dots>=4 or i>=s.length()) return;
	// recursion
	// take one char
	helper(s,dots+1,i+1,ans+s.substr(i,1)+'.',res);
	// take two chars
	if(i+2<=s.length() and is_valid(s.substr(i,2))){
		helper(s,dots+1,i+2,ans+s.substr(i,2)+'.',res);
	}
	// take three
	if(i+3<=s.length() and is_valid(s.substr(i,3))){
		helper(s,dots+1,i+3,ans+s.substr(i,3)+'.',res);
	}
	return;
}

int main(){
	string s;cin>>s;
	vector<string> res;
	helper(s,0,0,"",res);
	for(int i=0;i<res.size();i++){
		cout << res[i] << endl;
	}
}