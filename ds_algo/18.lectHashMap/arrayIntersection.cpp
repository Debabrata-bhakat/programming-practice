#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
void solve();

vector<int> arrayIntersection(vector<int> a, vector<int> b){
    unordered_map<int,int> seen;
    vector<int> output;
    for (int i = 0; i < a.size(); i++)
    {
        seen[a[i]] = 1;
    }
    for (int i = 0; i < b.size(); i++)
    {
        // check presence in map
        if(seen.count(b[i])>0){
            output.push_back(b[i]);
        }
    }
    return output;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}

void solve(){
    int n,m;
    vector<int> a,b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }
    vector<int> output = arrayIntersection(a,b);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;
}