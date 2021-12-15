#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int subZero(vector<int> a){
    unordered_map<int, int> seen;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int curr_len;
        sum += a[i];
        // check presence
        if(seen.count(sum)>0){
            curr_len = i - seen[sum];
            if(curr_len>ans) ans = curr_len;
        }else{
            seen[sum] = i;
        }
    }
    return ans;
}

int main(){
    int n; cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int t; cin >> t;
        a.push_back(t);
    }
    cout << subZero(a) << endl;
}