#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &in, stack<int> &out){
    // Base case
    if(in.size() == 1) return;
    // store the top most element
    int temp = in.top();
    in.pop();
    solve(in, out);
    // Transfer elements to the other empty stack
    while(!in.empty())
    {
        int a = in.top();
        out.push(a);
        in.pop();
    }
    // Add the temp element in the input stack
    in.push(temp);
    // Add back the elements from the other stack back
    while(!out.empty()){
        int a = out.top();
        in.push(a);
        out.pop();
    }
    
}

int main(){
    stack<int> s, res;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        s.push(temp);
    }
    solve(s,res);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;   
}