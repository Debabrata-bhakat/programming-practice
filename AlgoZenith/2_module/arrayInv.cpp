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

bool cmp(string str1, string str2){
    int s1_zero = count(str1.begin(), str1.end(), '0');
    int s1_one = count(str1.begin(), str1.end(), '1');
    int s2_zero = count(str2.begin(), str2.end(), '0');
    int s2_one = count(str2.begin(), str2.end(), '1');
    return (s1_one * s2_zero < s1_zero * s2_one);
}

void solve(){
    int n;cin>>n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    sort(a.begin(), a.end(), cmp);
    string res = "";
    for (int i = 0; i < n; ++i)
    {
        res += a[i];
    }
    char arr_char[res.length()]; int arr_count[res.length()];
    strcpy(arr_char,res.c_str());
    int curr=0;
    for (int i = 0; i < res.length(); ++i)
    {
        if(arr_char[i]=='1') curr++;
        arr_count[i] = curr;
    }
    int ans=0;
    for (int i = 0; i < res.length(); ++i)
    {
        if(arr_char[i]=='0') ans+=arr_count[i];
    }
    cout << ans << endl;
}