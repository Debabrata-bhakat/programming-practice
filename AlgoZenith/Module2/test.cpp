#include <bits/stdc++.h>
#define ull unsigned long long 
#define ll long long
using namespace std;

#define MAX 100005
bool prime[MAX + 1];
int mod = 1e9+7;
void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));
 
    prime[1] = false;
 
    for (int p = 2; p * p <= MAX; p++) {
 
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
 
            // Set all multiples of p to non-prime
            for (int i = p * 2; i <= MAX; i += p)
                prime[i] = false;
        }
    }
}
 
// find the sum of 1st N prime numbers
int solve2(int n)
{
    // count of prime numbers
    int count = 0, num = 1;
 
    // sum of prime numbers
    long long int sum = 0;
 
    while (count < n) {
 
        // if the number is prime add it
        if (prime[num]) {
            sum = (sum + num)%mod;
 
            // increase the count
            count++;
        }
 
        // get to next number
        num++;
    }
    return sum;
}

void solve();
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    ull t;
    // cin >> t;
    t=1;
    SieveOfEratosthenes();
    while(t--)
    {
        solve();
    }

}

void solve(){
	int n,k;cin>>n>>k;
	int res = solve2(n-1) + 1;
	res = (1LL*res*k)%mod;
	cout << res << endl;
}

