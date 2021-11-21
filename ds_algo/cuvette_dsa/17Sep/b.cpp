#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if(intervals[i][0]<=ans[ans.size()-1][1]) ans[ans.size()-1][1] = max(intervals[i][1],ans[ans.size()-1][1]);
        else{
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}

int main(){
    // vector<vector<int>> in = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> in = {{2,3},{4,5},{6,7},{1,10}};
    vector<vector<int>> ans = merge(in);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
}