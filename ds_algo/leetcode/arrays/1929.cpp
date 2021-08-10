#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums){
    int l = nums.size();
    vector<int> ans;
    for (int i = 0; i < l; i++)
    {
        ans.push_back(nums[i]);
    }
    for (int i = 0; i < l; i++)
    {
        ans.push_back(nums[i]);
    }
    return ans;
    
}

int main(){
    vector <int> g1{1,2,1};
    vector<int> ans = solve(g1);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}