#include <iostream>
#include <stack>
using namespace std;

int solve(string s){
    if(s.length()%2==1) return -1;
    stack<char> st;
    int c = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == '{') st.push(s[i]);
        else{
            if(st.empty()) st.push(s[i]);
            else if(st.top() == '{'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        } 
    }
    while (!st.empty())
    {
        char c1 = st.top();
        st.pop();
        char c2 = st.top();
        st.pop();
        if(c1 == c2) c++;
        else c += 2;
    }
    return c;
}

int main(){
    string s;
    cin >> s;
    cout << solve(s) << endl;
}