#include <iostream>
#include <queue>
using namespace std;

// Dynamic programming approach
int minSteps3(int n){
    int *ans = new int[n+1];
    // intialise all answers to -1;
    for (int i = 2; i <= n; i++)
    {
        ans[i] = -1;
    }
    ans[1] = 0;
    queue<int> index;
    index.push(1);
    while (index.size()!=0)
    {
        // take out the first index
        int curr_index = index.front();
        index.pop();
        int curr_value = ans[curr_index];

        // answer of next element
        if(curr_index+1<=n and ans[curr_index+1]==-1){
            ans[curr_index+1] = curr_value+1;
            index.push(curr_index+1);
        }
        // answer of index*2
        if(curr_index*2<=n and ans[curr_index*2]==-1){
            ans[curr_index*2] = curr_value+1;
            index.push(curr_index*2);
        }
        // answer of index*3
        if(curr_index*3<=n and ans[curr_index*3]==-1){
            ans[curr_index*3] = curr_value+1;
            index.push(curr_index*3);
        }
    }
    return ans[n];
}


// Memoization
int minSteps2_helper(int n, int *ans){
    // Base case
    if(n==1 or n==2 or n==3) return 1;

    // if answer already exists
    if(ans[n] != -1) return ans[n];

    // else calculate the answer
    int a=INT16_MAX, b=INT16_MAX, c=INT16_MAX;
    a = minSteps2_helper(n-1, ans);
    if(n%2==0) b = minSteps2_helper(n/2, ans);
    if(n%3==0) c= minSteps2_helper(n/3, ans);
    // save answer for future use
    ans[n] = min(a, min(b,c)) + 1;
    // return the answer
    return ans[n];
}

int minSteps2(int n){
    int *ans = new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        ans[i] = -1;
    }
    return minSteps2_helper(n, ans);
}

// Brute force approach
int minSteps(int n){
    // Base case
    if(n==1 or n==2 or n==3) return 1;

    int a=INT16_MAX, b=INT16_MAX, c=INT16_MAX;
    a = minSteps(n-1);
    if(n%2==0) b = minSteps(n/2);
    if(n%3==0) c= minSteps(n/3);
    return min(a,min(b,c))+1; 
}

int main(){
    int n; cin >> n;
    cout << minSteps3(n) << endl;
}