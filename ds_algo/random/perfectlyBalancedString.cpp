// https://codeforces.com/contest/1673/problem/B
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
    // t=1;
    while(t--) solve();
}

int find_unique(string s){
    vector<int> alph(26);
    for (int i = 0; i < 26; ++i)
    {
        alph[i] = 0;
    }
    for (int i = 0; i < s.length(); ++i)
    {
        alph[(s[i] - 'a')]++ ;
    }
    int unique=0;
    for (int i = 0; i < 26; ++i)
    {
        if(alph[i]>0) unique++;
    }
    return unique;
}

void solve(){
    string s;cin>>s;
    vector<int> alph(26);
    for (int i = 0; i < 26; ++i)
    {
        alph[i] = 0;
    }
    for (int i = 0; i < s.length(); ++i)
    {
        alph[(s[i] - 'a')]++ ;
    }
    int unique=0;
    for (int i = 0; i < 26; ++i)
    {
        if(alph[i]>0) unique++;
    }
    if(unique==1){
        cout <<  "YES\n";
        return;
    }
    string sunique = s.substr(0,unique);
    // cout << unique << '\n';
    // cout << sunique << '\n';
    if(find_unique(sunique)!=unique){
        cout << "NO\n";
        return;
    }
    string check = "";
    for (int i = 0; i < s.length()/unique; ++i)
    {
        check += sunique;
    }
    // cout << (s.length()/unique)*unique << '\n';
    check += sunique.substr(0,s.length()%unique);
    // cout << check << '\n';
    if(check == s) cout << "YES\n";
    else cout << "NO\n";
}