#include <bits/stdc++.h>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    vector<vector<string>> ans_sort;
    vector<string> in = strs;
    for (int i = 0; i < in.size(); i++)
    {
        sort(in[i].begin(), in[i].end());
    }
    
    for (int i = 0; i < in.size(); i++)
    {
        int  j = 0;
        for (j = 0; j < ans.size(); j++)
        {
            if(ans_sort[j][0]==in[i]){
                ans[j].push_back(strs[i]);
                ans_sort[j].push_back(in[i]);
                break;
            } 
        }
        if(j==ans.size()){
            vector<string> temp = {strs[i]};
            vector<string> temp2 = {in[i]};
            ans.push_back(temp);
            ans_sort.push_back(temp2);
        }
    }
    return ans;
}

int main(){
    // vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;    
    }
    
}