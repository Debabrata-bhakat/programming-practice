#include <bits/stdc++.h>
using namespace std;



int main() {
	// Your code goes here;
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL); 
	vector<int> arr;	
    int n = arr.size();
    vector<vector<int>> res;
    sort(arr.begin(),arr.end());
    cout << "asf " << arr.size() <<endl;

    for(int j=1;j<arr.size()-1;j++){
    cout << "bgb " << j <<endl;
        int i=0,k=n-1;
        while(i<j and j<k){
            int curr = arr[i]+arr[j]+arr[k];
            if(curr==0){
                vector<int>temp = {arr[i],arr[j],arr[k]};
                res.push_back(temp);
            }
            if(curr>0) k--;
            else i++;
        }
    }
    // insert into a set
    set<vector<int>> s1;
    for(auto x:res){
        s1.insert(x);
    }
    // insert into vector
    vector<vector<int>> ans;
    for(auto x:s1){
        ans.push_back(x);
    }
    return 0;
}