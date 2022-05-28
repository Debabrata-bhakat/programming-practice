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

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    cin >> t;
    // t=1;
    while(t--) solve();
}

bool first_case(vector<double> arr){
    if(arr.size()<3) return false;
    priority_queue<double> q(arr.begin(),arr.end());
    double sum=0;
    for(int i=0;i<3;i++){
        sum+= q.top(); q.pop();
    }
    cout << sum << endl;
    if(sum>1) return true; else return false;
}

bool third_case(vector<double> A, vector<double> C){
    if(A.size()<2 or C.size()<1) return false;
    priority_queue<double, vector<double>, greater<double>> qa(A.begin(), A.end());
    priority_queue<double, vector<double>, greater<double>> qc(C.begin(), C.end());
    double sum=0;
    for(int i=0;i<2;i++){
        sum += qa.top(); qa.pop();
    }
    sum += qc.top(); qc.pop();
    if(sum>1 and sum<2) return true;
    else return false;
}


void solve(){
	vector<string> a {"2.671613", "1.239175", "2.575260", "0.021242", "1.894100", "0.148016", "0.341571" };
	int n = a.size();
	vector<double> arr(n);
    for(int i=0;i<n;i++){arr[i] = stod(a[i]);}
    // form A B and C array
    vector<double> A1;
    vector<double> B;
    vector<double> C;
    for(int i=0;i<n;i++){
        if(arr[i]<2.0/3.0) A1.push_back(arr[i]);
        if(arr[i]>=2.0/3.0 and arr[i]<=1) B.push_back(arr[i]);
        if(arr[i]>1 and arr[i]<2) C.push_back(arr[i]);
    }
    for(int i=0;i<A1.size();i++){
    	cout << A1[i] << " " ;
    }
    cout << endl;
    cout << third_case(A1,C) << endl;

}

// 2.671613 1.239175 2.575260 0.021242 1.894100 0.148016 0.341571