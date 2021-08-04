// Build Array from Permutation
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <vector>


vector<int> buildArray(vector<int> &nums){
    vector<int> ans(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
       ans[i] = nums[nums[i]]; 
    }
    return ans;
        
    
}


int main(){
   vector<int> vect{ 0,2,1,5,3,4 };
   vector<int> ans = buildArray(vect);
   for (int i = 0; i < ans.size(); i++)
   {
    cout << ans[i] << " ";   
   }
  cout << '\n'; 
}