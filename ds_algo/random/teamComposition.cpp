// https://codeforces.com/contest/1611/problem/B
#include <bits/stdc++.h>
#define ull unsigned long long 
#define ll long long
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

void solve(){
    ull a,b; cin>>a>>b;
    cout << min((a+b)/4,min(a,b)) << '\n';
}


void solve2(){
    ull a,b; cin>>a>>b;
    if(a==0 or b==0){
        cout << "0\n";
        return;
    }
    if(a==b){
        cout << a/2 << '\n';
        return;
    }
    cout << "helo";
    ull c=0;
    ull a1;
    ull b1;
    while(a>0 and b>0){
        if(a==b){
            c = c + a/2;
            break;
        }
        if(a>b){
            a1 = a/3;
            b1 = b/1;
            ull t = min(a1,b1);
            c += t;
            a = a - t*3;
            b = b - t*1;
        }else{
            a1 = a/1;
            b1 = b/3;
            ull t = min(a1,b1);
            c += t;
            a = a - t*1;
            b = b - t*3;
        }
        if(a1==0 or b1==0) break;
    }
    cout << c << '\n';
}




































void solve3(){
    ll a,b; cin>>a>>b;
    if(a==0 or b==0){
        cout << "0\n";
        return;
    }
    if(a==b){
        cout << a/2 << '\n';
        return;
    }
    ll c=0;
    while(a>0 and b>0){
        if(a==b){
            c = c + a/2;
            break;
        }
        if(a>b){
            if(a<3)break;
            a=a-3;
            b=b-1;
        }else{
            if(b<3) break;  
            a=a-1;
            b=b-3;
        }
        c++;
    }
    cout << c << '\n';
}

