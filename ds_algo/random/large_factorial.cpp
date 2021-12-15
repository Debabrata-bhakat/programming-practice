// https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1#problems
#include <iostream>
#include <vector>
using namespace std;
vector<int> factorial(int N){
    // code here
    int a[1000] = {0};
    a[0] =  1;
    int carry = 0, size = 1;
    for(int i  = 2; i <= N; i++){
        for(int j = 0; j<size; j++){
            int temp = (a[j]*i + carry);
            a[j] = temp%10;
            carry = temp/10;
        }
        while(carry){
            a[size] = carry%10;
            carry = carry/10;
            size++;
        }
    }
    vector<int> output;
    for(int i=size-1; i>=0; i--){
        output.push_back(a[i]);
    }
    return output;
}

int main(){
    int n; cin >> n;
    vector<int> output = factorial(n);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] ;
    }
    cout << endl;
}
