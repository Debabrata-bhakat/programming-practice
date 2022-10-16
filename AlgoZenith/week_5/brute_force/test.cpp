#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string A) {
    stack<string> st;
    int n = A.length(); string dir="";
    for(int i=0;i<n;i++){
        char ch=A[i];
        if(ch=='/'){
            if(dir==".." ){
                if(!st.empty())st.pop();
            }else if(dir!="." and dir!=""){
                st.push(dir);
            }
            dir="";
        }else{
            dir=dir+ch;
        }
    }
    if(dir==".." ){
        if(!st.empty())st.pop();
    }else if(dir!="." and dir!=""){
        st.push(dir);
    }
    string res="";
    while(!st.empty()){
        string curr=st.top(); st.pop();
        res = curr+"/"+res;
    }
    res=res.substr(0,res.length()-1);
    res="/"+res;
    return res;
}

int main() {
	// Your code goes here;
	string s; cin>>s;
	cout << simplifyPath(s) << endl;
    return 0;
}