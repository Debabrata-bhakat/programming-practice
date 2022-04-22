#include <bits/stdc++.h>
using namespace std;


int findSum(int n, int m, vector<int> a){
    // Sort the vector in descending order
    sort(a.begin(), a.end(), greater<int>());
    int sum=0;
    int flag = 0;
    int index=0;
    while(m>0){
        if(flag==0){
            sum += a[index]*2;
            flag = (flag+1)%3;
            m--;
            continue;
        }
        if(flag==1){
            if(index+1 >= a.size()) return 0;
            sum += a[index] + a[index+1];
            m--;
            flag = (flag+1)%3;
            continue;
        }
        if(flag==2){
            if(index+1 >= a.size()) return 0;
            sum += a[index] + a[index+1];
            flag = (flag+1)%3;
            m--;
            continue;
        }
    }
    return sum;
}

int main(){
    int n; cin >> n;
    int m; cin >> m;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        a.push_back(temp);
    }
    cout << findSum(n,m,a) << endl;
}