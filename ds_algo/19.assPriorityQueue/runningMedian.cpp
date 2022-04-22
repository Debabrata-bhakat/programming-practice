#include <iostream>
#include <queue>
using namespace std;


void printRunningMedian(vector<int> a){
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
    for (int i = 0; i < a.size(); i++)
    {
        // if both heaps are empty
        if(min_heap.size()==0 and max_heap.size()==0){
            max_heap.push(a[i]);
            cout << a[i] << " ";
            continue;
        }

        // if element is more than max of max_heap: insert it in min_heap
        if(max_heap.top()<a[i]){
            min_heap.push(a[i]);
            // if in doing so the size of min_heap is more than max_heap by 2 then move an element from min_heap to max_heap
            if(min_heap.size() > (max_heap.size()+1)){
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }else{ //else push insert it in max_heap
            max_heap.push(a[i]);
            // if in doing so the size of max_heap is more than min_heap by 2 then move an element from max_heap to min_heap
            if(max_heap.size() > (min_heap.size()+1)){
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
        }
        // find the median
        if(max_heap.size() == min_heap.size()) cout << (max_heap.top() + min_heap.top())/2 <<  " ";
        else if(max_heap.size() > min_heap.size()) cout << max_heap.top() <<  " ";
        else cout << min_heap.top() << " ";
    }
    cout << '\n';   
}

int main(){
    int s; cin >> s;
    vector<int> a;
    for (int i = 0; i < s; i++)
    {
        int temp; cin >> temp;
        a.push_back(temp);
    }
    printRunningMedian(a);
}