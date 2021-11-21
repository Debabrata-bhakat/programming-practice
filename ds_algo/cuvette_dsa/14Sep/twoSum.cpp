#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    unordered_map<int,int> map;
    for(int i = 0; i< nums.size(); i++){
        int a = target - nums[i];
        if (map.find(a) != map.end()){
            ans.push_back(i);
            ans.push_back(map[a]);
            break;
        }
        else{
            map[nums[i]] = i;
        }
    }
    return ans;
}

int main(){
    vector<int> test = {3,3};
    vector<int> res = twoSum(test, 6);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;;
    }
}
