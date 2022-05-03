#include <iostream>
using namespace std;
using lli = long long int;

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
// int binary_exponentiation(int a, int b, int mod){
// 	int ans = 1;
// 	while(b){
// 		if(b%2==1){
// 			ans = 1LL*ans*a %mod;
// 		}
// 		a = 1LL*a*a %mod;
// 		b/=2;
// 	}
// 	return ans;
// }


int main(){
	int a,b; cin >> a;// >> b;
	// cout << binary_exponentiation(a,b,1e9+7) << "\n";
	// inverse modulo
	// a^-1 mod p = a^(p-2) mod p
	// O(log p)
	cin >> b;
	// cout << binary_exponentiation(a,1e9+7-2,1e9+7) << '\n';
	cout << binary_exponentiation(a,b,1e9+7) << '\n';
}