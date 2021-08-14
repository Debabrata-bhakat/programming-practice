#include <iostream>
#include <queue>
using namespace std;

void solve(queue<int> &q){
    // Base case
    if(q.size() == 1) return;
    // Store the first element
    int temp = q.front();
    q.pop();
    solve(q);
    // Push back the element
    q.push(temp);
}

int main(){
    queue<int> q;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int a;
        cin >> a;
        q.push(a);
    }
    solve(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}