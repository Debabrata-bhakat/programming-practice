#include <iostream>
#include <queue>
using namespace std;

int *kSmallest2(int *a, int k, int n){
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(a[i]);
    }
    int *res = new int[k];
    for (int i = 0; i < k; i++)
    {
        res[i] = pq.top();
        pq.pop();
    }
    return res;
}

int *kSmallest(int *a, int k, int n){
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(a[i]);
    }
    for (int i = k; i < n; i++)
    {
        if(pq.top()>a[i]){
            pq.pop();
            pq.push(a[i]);
        }
    }
    int *res = new int[k];
    for (int i = 0; i < k; i++)
    {
        res[i] = pq.top();
        pq.pop();
    }
    return res;
}

int main(){
    int n; cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k; cin >> k;
    int *res = kSmallest(a,k,n);
    for (int i = 0; i < k; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}
