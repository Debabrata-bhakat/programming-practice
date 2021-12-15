#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int maxFreq(vector<int> a){
    unordered_map<int,int> freq;
    int max = 1;
    int max_n = a[0]; 
    for (int i = 0; i < a.size(); i++)
    {
        freq[a[i]] = freq[a[i]] + 1;
        if(max<freq[a[i]]){
            max = freq[a[i]];
            max_n = a[i];
        }
    }
    return max_n;
}

int main(){
    int size;
    cin >> size;
    vector<int> in;
    for (int i = 0; i < size; i++)
    {
        int n;
        cin >> n;
        in.push_back(n);
    }
    int res = maxFreq(in);
    cout << res << endl;
}