#include <iostream>
#include <queue>
using namespace std;

int kthLargest(vector<int> a, int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(a[i]);
    }
    for (int i = k; i < a.size(); i++)
    {
        if(a[i]>pq.top()){
            pq.pop();
            pq.push(a[i]);
        }
    }
    return pq.top();
}

int main(){
    int n; cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        a.push_back(temp);
    }
    int k; cin >>k;
    cout << kthLargest(a,k) << endl;
}