#include <bits/stdc++.h>
#define ull unsigned long long 
using lli = long long int;
using namespace std;
int mod = 1e9+7;
void solve();
// calculate a^b mod 10^9+7
lli binary_exponentiation(lli a, lli b,  lli mod){
   lli ans=1;
   while(b>0){
      if(b%2==1){
         ans = (ans*a) % mod;
      }
      a = (a*a) %mod;
      b/=2;
   }
   return ans;
}

int gcd(int a, int b){
   if(a==0 or b==0) return a^b;
   return __gcd(a,b);
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    cin >> t;
    // t=1;
    while(t--) solve();
}
vector<int> ph(vector<int> index, vector<int> indentity){
   vector<int> ans;
   int n = index.size();
   for(int i=0;i<n;i++){
      if(index[i]>=ans.size()){
         ans.push_back(indentity[i]);
      }else{
         ans.insert(ans.begin()+index[i],indentity[i]);
      }
   }
   return ans;
}
void solve(){
   int n;cin>>n;
   vector<int> arr1(n); 
   vector<int> arr2(n); 
   for(int i=0;i<n;i++) cin>>arr1[i];
   for(int i=0;i<n;i++) cin>>arr2[i];
   vector<int> res=ph(arr1,arr2);
   for(auto x:res) cout << x << " ";
   
}