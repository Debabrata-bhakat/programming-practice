#include <iostream>
#include <stack>
using namespace std;

bool solve(string exp){
    stack<char> s;
    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];
        if(ch!=')'){
            s.push(ch);
        }
        else{
            int c = 0;
            while (s.top()!='(')
            {
                c++;
                s.pop();
            }
            if(c==0 or c==1) return true;
        }
    }
    return false;
}

int main(){
    string exp;
    cin >> exp;
    cout << solve(exp) << endl;
}