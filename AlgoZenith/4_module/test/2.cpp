// #include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
// #include<string>
#include<iostream>
using namespace std;


string first(string s){
	int n = s.length();
	int sum=0;
	for (int i = 0; i < n; ++i)
	{
		int curr = s[i];
		if(curr>=48 and curr<=57){
			sum+= (curr-48);
		}
	}
	return to_string(sum);
}

string second(string s){
	int n = s.length();
	string ans="";
	for (int i = 0; i < n; ++i)
	{
		char curr = s[i];
		if((curr>=65 and curr<=90) or (curr>=97 and curr<=122) ){
			ans += curr;
		}
	}
	return ans;
}

// char* first(char* s){
// 	int n = strlen(s);
// 	int sum=0;
// 	for (int i = 0; i < n; ++i)
// 	{
// 		int curr = s[i];
// 		if(curr>=48 and curr<=57){
// 			sum+= (curr-48);
// 		}
// 	}
// 	return to_string(sum);
// }

char* test(char* input1, int input2){
	int size = strlen(input1);
	string s(input1, input1 + size);
	if(s.length()==0){
		cout << "NULL\n"; return NULL;
	} 
	if(input2==1) {
		string ans = first(s);
		cout << ans << endl;
		char *cstr = new char[ans.length() + 1];
		strcpy(cstr, ans.c_str());
		return cstr;
	}
	else{
		string ans = second(s);
		cout << ans << endl;
		char *cstr = new char[ans.length() + 1];
		strcpy(cstr, ans.c_str());
		return cstr;
	}

}
// char* test(char* input1, int input2){
// 	int size = strlen(input1);
// 	string s(input1, input1 + size);
// 	if(s.length()==0){
// 		return NULL;
// 	} 
// 	if(input2==1) {
// 		string ans = first(s);
// 		char *cstr = new char[ans.length() + 1];
// 		strcpy(cstr, ans.c_str());
// 		return cstr;
// 	}
// 	else{
// 		string ans = second(s);
// 		char *cstr = new char[ans.length() + 1];
// 		strcpy(cstr, ans.c_str());
// 		return cstr;
// 	}

// }

int main(){
	int n;cin>>n;
	string s;cin>>s;
	char *cstr = new char[s.length() + 1];
	strcpy(cstr, s.c_str());
	test(cstr,n);
	// if(s.length()==0){
	// 	cout << "NULL\n"; return 0;
	// } 
	// if(n==1) cout << first(s) << endl;
	// else cout << second(s) << endl;
}