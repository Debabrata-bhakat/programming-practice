#include <iostream>
using namespace std;

int solve(int n){
    // Base case
    if(n==0)
    return 1;
    if(n<0)
    return 0;
    int first_case = solve(n-1);
    int second_case = solve(n-2);
    int third_case = solve(n-3);
    return first_case + second_case + third_case;
    
    // return first_case + second_case + third_case + 3;
}

int main(){
    int n;
    cin >> n;
    cout << solve(n) << endl;
}