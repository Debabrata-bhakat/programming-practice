#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int pairSum(vector<int> a){
    int c=0;
    unordered_map<int,int> neg;
    for (int i = 0; i < a.size(); i++)
    {
        neg[-a[i]] +=  1;
    }
    for (int i = 0; i < a.size(); i++)
    {
        // check presence
        if(neg.count(a[i])>0){
            c+=neg[a[i]];
        }
    }
    return c/2;
}

int main(){
    int n;
    cin >> n;
    vector<int> in;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        in.push_back(temp);
    }
    cout << pairSum(in) << endl;
}