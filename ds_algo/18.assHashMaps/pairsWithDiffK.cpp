#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int pairs(vector<int> a, int k){
    unordered_map<int, int> seen;
    for (int i = 0; i < a.size(); i++)
    {
        seen[a[i]] += 1;
    }
    int c=0;
    unordered_map<int,int>::iterator it = seen.begin();
    while(it!=seen.end()){
        int curr = it->first;
        int n1 = curr - k;
        // check for presence
        if(seen.count(n1)>0){
            c += seen[n1]*seen[curr];
        }
        n1 = curr + k;
        // check for presence
        if(seen.count(n1)>0){
            c += seen[n1]*seen[curr];
        }
        // do not check for this once again
        seen[curr] = 0;
        it++;
    }
    return c;
}

int main(){
    int n; cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int t; cin >> t;
        a.push_back(t);
    }
    int k; cin >> k;
    cout << pairs(a,k) << endl;
}