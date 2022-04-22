// https://codeforces.com/contest/1618/problem/C
#include <bits/stdc++.h>
#define ull unsigned long long 
using namespace std;
void solve();
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    ull t;
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

// Function to prull the divisors
vector<ull> prullDivisors(ull n)
{
    vector<ull> res;
    // Note that this loop runs till square root
    for (ull i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, prull only one
            if (n/i == i)
                // cout <<" "<< i;
                res.push_back(i);
  
            else // Otherwise prull both
                // cout << " "<< i << " " << n/i;
                res.push_back(i);
                res.push_back(n/i);
        }
    }
    return res;
}

void solve2(){
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

    vector<ull> first_div = prullDivisors(min_even);
    for (ull i = 0; i < first_div.size(); i++)
    {
        if(check(a,first_div[i])){
            cout << i << '\n';
            return;
        }
    }
    vector<ull> second_div = prullDivisors(min_odd);
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

ull gcd (ull a, ull b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

void solve(){
    ull n; cin >> n;
    vector<ull> a;
    for (ull i = 0; i < n; i++)
    {
        ull temp; cin >> temp;
        a.push_back(temp);
    }
    ull res_1 = a[0], res_2=a[1];
    for (ull i = 2; i < n; i=i+2)
    {
        res_1 = gcd(a[i],res_1);
    }
    for (ull i = 3; i < n; i=i+2)
    {
        res_2 = gcd(a[i],res_2);
    }
    if(check(a,res_1)) {
        cout << res_1 <<  "\n";
    }else if(check(a,res_2)){
        cout << res_2 << "\n";
    }else {
        cout << "0\n";
    }
}

