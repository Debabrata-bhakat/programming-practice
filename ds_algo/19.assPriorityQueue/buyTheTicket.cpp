#include <iostream>
#include <queue>
using namespace std;

int findTime(vector<int> a, int m){
    // make a max priority queue
    priority_queue<int> pq;
    queue<int> q;
    for (int i = 0; i < a.size(); i++)
    {
        pq.push(a[i]);
        q.push(a[i]);
    }
    int time = 0;
    int curr_index = m;
    int last_index = a.size()-1;
    while (q.size()!=0)
    {
        int curr = q.front();
        // if it matches the condition of giving the ticket
        if(curr==pq.top()){
            time++;
            pq.pop();
            q.pop();
            // if curr is my index then return the time
            if(curr_index == 0) return time;
            curr_index--;
            last_index--;
        }else{
            q.pop();
            q.push(curr);
            curr_index--;
        }
        if(curr_index<0) curr_index = last_index;
    }
    
    return 0;
}

int main(){
    int n; cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        a.push_back(temp);
    }
    int m; cin >> m;
    cout << findTime(a,m) << '\n';
}