#include <iostream>
using namespace std;
#include <stack>

bool balance(string exp){
    stack<char> st;
    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];
        if(c == '{' or c == '(' or c == '['){
            st.push(c);
        }
        else if(c == '}' or c == ')' or c== ']'){
            char top_element = st.top();
            if( (c=='}' and top_element=='{') or (c==')' and top_element=='(') or (c==']' and top_element=='[') ){
                st.pop();
            }
            else return false;
        }
    }
    return st.size()==0;
}

int main(){
    string exp;
    cin >> exp;
    cout << balance(exp) << endl;
}