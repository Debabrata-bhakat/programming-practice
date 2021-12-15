// https://codeforces.com/contest/1613/problem/0
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

ull len_num(ull x){
    ull ans = 0;
    while(x>0){
        x = x/10;
        ans++;
    }
    return ans;
}

ull firstDigit(ull n)
{
    // Find total number of digits - 1
    ull digits = (ull)log10(n);
 
    // Find first digit
    n = (ull)(n / pow(10, digits));
 
    // Return first digit
    return n;
}

void solve2(){
    ull x1, p1, x2, p2; cin >> x1 >> p1 >> x2 >> p2;
    if(x1==0) p1=0;
    if(x2==0) p2=0;
    while(x1%10==0 and x1>0){
        x1 = x1/10;
        p1++;
    }
    while(x2%10==0 and x2>0){
        x2 = x2/10;
        p2++;
    }
    // cout << x1 << " " << p1 << " " << x2 << " " << p2 ;
    if((len_num(x1) + p1) > (len_num(x2) + p2)){
        cout << ">\n";
        return;
    }else if ((len_num(x1) + p1) < (len_num(x2) + p2)){
        cout << "<\n";
        return;
    }

    ostringstream str1;
    str1 << x1;
    string geek1 = str1.str();
    ostringstream str2;
    str2 << x2;
    string geek2 = str2.str();
    for (ull i = 0; i < min(geek1.length(), geek2.length()); i++)
    {   
        if(geek1[i] > geek2[i]){
            cout << ">\n";
            return;
        }else if(geek2[i] > geek1[i]){
            cout << "<\n";
            return;
        }
    }
    cout << "=\n";
    

    // while(x1>0 and x2>0){
    //     ull f1 = firstDigit(x1);
    //     ull f2 = firstDigit(x2);
    //     if(f1>f2){
    //         cout << ">\n";
    //         return;
    //     }else if(f2>f1){
    //         cout << "<\n";
    //         return;
    //     }
    //     x1 = x1/10;
    //     x2 = x2/10;
    // }
    
}

void solve(){
    ull x1, p1, x2, p2; cin >> x1 >> p1 >> x2 >> p2;
    if(x1==0) p1=0;
    if(x2==0) p2=0;
    while(x1%10==0 and x1>0){
        x1 = x1/10;
        p1++;
    }
    while(x2%10==0 and x2>0){
        x2 = x2/10;
        p2++;
    }
    // cout << x1 << " " << p1 << " " << x2 << " " << p2 ;
    if((len_num(x1) + p1) > (len_num(x2) + p2)){
        cout << ">\n";
        return;
    }else if ((len_num(x1) + p1) < (len_num(x2) + p2)){
        cout << "<\n";
        return;
    }

    ostringstream str1;
    str1 << x1;
    string geek1 = str1.str();
    ostringstream str2;
    str2 << x2;
    string geek2 = str2.str();

    int x = geek1.compare(geek2);
    if(x>0){
        cout << ">\n";
        return;
    }else if(x<0){
        cout << "<\n";
        return;
    }else{
        cout <<"=\n";
        return;
    }
}