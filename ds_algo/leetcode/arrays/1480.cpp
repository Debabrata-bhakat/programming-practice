#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> nums){
    int one_sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        one_sum += nums[i];
        nums[i] = one_sum;
    }
    return nums;
}

int main(){
    vector<int> a{1,2,3,4};
    vector<int> ans = solve(a);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}