// https://codeforces.com/contest/1618/problem/C
#include <bits/stdc++.h>
#define ull unsigned long long 
using namespace std;
void solve();
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

bool check(vector<ull> a, ull k){
    ull flag;
    if(a[0]%k==0) flag=1;
    else flag=0;
    for (ull i = 1; i < a.size(); i++)
    {
        ull temp = (a[i]%k == 0);
        // cout << a[i] << ":  " << temp << '\n';
        if(temp==flag){
            return false;
        }
        flag = temp;
    }
    return true;
}

// Function to print the divisors
vector<ull> printDivisors(ull n)
{
    vector<ull> res;
    // Note that this loop runs till square root
    for (ull i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                // cout <<" "<< i;
                res.push_back(i);
  
            else // Otherwise print both
                // cout << " "<< i << " " << n/i;
                res.push_back(i);
                res.push_back(n/i);
        }
    }
    return res;
}

void solve(){
    ull n; cin >> n;
    vector<ull> a;
    ull temp; cin >> temp;
    ull min_even=temp;
    a.push_back(temp);
    cin >> temp;
    ull min_odd = temp;
    a.push_back(temp);
    for (ull i = 2; i < n; i++)
    {
        ull temp; cin >> temp;
        if(i%2==0 and min_even>temp) min_even = temp;
        if(i%2!=0 and min_odd>temp) min_odd = temp;
        a.push_back(temp);
    }
    // cout << check(a,3);
    // ull l=1,r=1e18;
    // while(l<=r){
    //     ull mid = (l+r)/2;
    //     if(check(a,mid)){
    //         cout << mid << '\n';
    //         return;
    //     }
    // }

    for (ull i = 0; i < n; i++)
    {
        if(check(a,a[i])){
            cout << a[i] << '\n';
            return;
        }
        
    }

    vector<ull> first_div = printDivisors(min_even);
    for (ull i = 0; i < first_div.size(); i++)
    {
        if(check(a,first_div[i])){
            cout << i << '\n';
            return;
        }
    }
    vector<ull> second_div = printDivisors(min_odd);
    for (ull i = 0; i < second_div.size(); i++)
    {
        if(check(a,second_div[i])){
            cout << i << '\n';
            return;
        }
    }
    
    
    

    // for (ull i = 1; i <= a[0]; i++)
    // {
    //     if(a[0]%i!=0) continue;
    //     if(check(a,i)){
    //         cout << i << '\n';
    //         return;
    //     }
    // }
    // for (ull i = 1; i <= a[1]; i++)
    // {
    //     if(a[1]%i!=0) continue;
    //     if(check(a,i)){
    //         cout << i << '\n';
    //         return;
    //     }
    // }
    
    
    cout << "0\n";
}