// https://codeforces.com/contest/1608/problem/B
#include <bits/stdc++.h>
#define ull unsigned long long 
#define ll long long
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



void solve(){
    // cout << "he\n";
    int n,a,b; cin >> n >> a >> b;
    n=n-2;
    if(a+b>n or a>(n+1)/2 or b>(n+1)/2){
        cout << "-1\n";
        return;
    }
    if(abs(a-b)>1){
        cout << "-1\n";
        return;
    }
    n=n+2;
        if(a==0 and b==0){
        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << '\n';
        return;
    }
    int si=1, ei=n;
    int res[n], size=1;
    // if max is more
    int flag = 0;
    if(a>b){
        b = b - (a-1);
        while(a>0){
            res[size-1] = si;
            size++;
            si++;
            flag = 0;
            res[size-1] = ei;
            size++;
            ei--;
            flag = 1;
            a--;
        }
        if(b>0){
            res[size-1] = si;
            flag = 0;
            size++;
            si++;
        }
    }else{
        a = a - (b-1);
        while(b>0){
            res[size-1] = ei;
            flag = 1;
            size++;
            ei--;
            res[size-1] = si;
            flag = 0;
            size++;
            si++;
            b--;
        }
        if(a>0){
            res[size-1] = ei;
            flag = 1;
            size++;
            ei--;
        }
    }
    if (flag == 0){
        while(size<=n){
        res[size-1] = si;
        si++;
        size++;
        }       
    }else{
        while(size<=n){
        res[size-1] = ei;
        ei--;
        size++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << '\n';
}

// void solve2(){
//     int n,a,b; cin >> n >> a >> b;
//     n=n-2;
//     if(a+b>n or a>(n+1)/2 or b>(n+1)/2){
//         cout << "-1\n";
//         return;
//     }
//     if(abs(a-b)>1){
//         cout << "-1\n";
//         return;
//     }
//     n=n+2;
//     if(a==0 and b==0){
//         for (int i = 1; i <= n; i++)
//         {
//             cout << i << " ";
//         }
//         cout << '\n';
//         return;
//     }
//     int si=1, ei=n;
//     int res[n], size=1;
//     // if max is more
//     if(a>b){
//         b = b - (a-1);
//         while(a>0){
//             res[size-1] = si;
//             size++;
//             si++;
//             res[size-1] = ei;
//             size++;
//             ei--;
//             a--;
//         }
//         while(b>0){
//             res[size-1] = si;
//             size++;
//             si++;
//             res[size-1] = ei;
//             size++;
//             ei--;
//             b--;
//             // res[size-1] = ei;
//             // size++;
//             // ei--;
//             // res[size-1] = si;
//             // size++;
//             // si++;
//             // b--;
//         }
//     }else{
//         a = a - (b-1);
//         while(b>0){
//             res[size-1] = ei;
//             size++;
//             ei--;
//             res[size-1] = si;
//             size++;
//             si++;
//             b--;
//         }
//         while(a>0){
//             res[size-1] = ei;
//             size++;
//             ei--;
//             res[size-1] = si;
//             size++;
//             si++;
//             a--;
//             // res[size-1] = si;
//             // size++;
//             // si++;
//             // res[size-1] = ei;
//             // size++;
//             // ei--;
//             // a--;
//         }
//     }
//     // size--;
//     // cout << size << " hesd" << n << '\n';
//     while(size<=n){
//         res[size-1] = si;
//         si++;
//         size++;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << res[i] << " ";
//     }
//     cout << '\n';
// }