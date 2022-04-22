// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> jugglerSequence(int N){
        // code here
        // base case
        if(N==1){
            vector<int> temp;
            temp.push_back(1);
            return temp;
        }
        // working
        vector<int> res;
        res.push_back(N);
        int next_term;
        if(N % 2 == 0){
            next_term = (int)pow(N,0.5);
        }else{
            next_term = (int)pow(N,1.5);
            // cout << "lskdj\n";
        }
        // cout << "next_term " << next_term << " N " << N << endl;
        // recursion
        vector<int> smallOutput;
        smallOutput = jugglerSequence(next_term);
        
        for(int i=0;i<smallOutput.size();i++){
            res.push_back(smallOutput[i]);
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.jugglerSequence(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<endl;
        // cout << "lkfjdsal\n";
    }
    return 0;
}  // } Driver Code Ends