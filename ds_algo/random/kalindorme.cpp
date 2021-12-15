// https://codeforces.com/contest/1610/problem/B
#include <bits/stdc++.h>
#define ull unsigned long long 
using namespace std;
void solve2();
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    cin >> t;
    while(t--)
    {
        solve2();
    }
}

bool checkPalindrome(vector<int> a){
    bool isPalin = true;
    for (int i = 0; i < a.size()>>1; i++)
    {
        if(a[i]!=a[a.size()-1-i]) isPalin=false;
    }
    return isPalin;
}


vector<int> removeElements(vector<int> a,int x){
    for (int i = 0; i < a.size(); i++)
    {
        if(a[i]==x) a.erase(a.begin()+i);
    }
    return a;
}

void solve(){
    int n; cin >> n;
    vector<int> in;
    for (int i = 0; i < n; i++)
    {
        int t;cin>>t;
        in.push_back(t);
    }
    // if it is already palindrome
    if(checkPalindrome(in)){
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < in.size()>>1; i++)
    {
        // find the first i where mismatch takes place
        if(in[i]==in[in.size()-1-i]) continue;
        vector<int> res1 = removeElements(in,in[i]);
        vector<int> res2 = removeElements(in,in[in.size()-i-1]);
        if(checkPalindrome(res1) or checkPalindrome(res2)){
            cout << "YES\n";
            return;
        }else{
            cout << "NO\n";
            return;
        }
    }
}


// modified solution
const int xn = 2e5 + 10;
int qq, n, m, a[xn], b[xn];
bool ans;
void check(int x){
	m = 0;
	for (int i = 1; i <= n; ++ i)
		if (a[i] != x)
			b[++ m] = a[i];
	for (int i = 1; i <= m; ++ i)
		if (b[i] != b[m + 1 - i])
			return;
	ans = true;
}
void solve2(){
    cin >> n, ans = true;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i];
		for (int i = 1; i <= n; ++ i){
			if (a[i] != a[n + 1 - i]){
				ans = false;
				check(a[i]);
				check(a[n + 1 - i]);
				break;
			}
		}
		if (ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
}