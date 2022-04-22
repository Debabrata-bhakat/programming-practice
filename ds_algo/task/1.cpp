#include <iostream>
#include <queue>
using namespace std;

class Box{
    public:
    int element;
    int array_index;
    int index_element;

    Box(int element, int array_index, int index_element){
        this->element = element;
        this->array_index = array_index;
        this->index_element = index_element;
    }
};

bool operator>(Box b1, Box b2){
    return b1.element>b2.element;
}

int main(){
    // Box b1(3,5,6);
    // Box b2(45,6,0);
    // cout << (b1 < b2) << endl; 

    int n; cin >>n;
    vector<vector<int>> a;
    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        vector<int> temp_array;
        for (int i = 0; i < k; i++)
        {
            int temp; cin >> temp;
            temp_array.push_back(temp);
        }
        a.push_back(temp_array);
    }
    vector<int> res;
    priority_queue<Box, vector<Box>, greater<Box>> pq;
    for (int i = 0; i < n; i++)
    {
        Box temp(a[i][0], i, 0);
        pq.push(temp);
    }
    
    while(!pq.empty()){
        Box curr = pq.top();
        pq.pop();
        res.push_back(curr.element);
        int curr_array_index = curr.array_index;
        int curr_element_index = curr.index_element;
        if((curr_element_index+1) < a[curr_array_index].size()){
            Box temp(a[curr_array_index][curr_element_index+1], curr_array_index, curr_element_index+1);
            pq.push(temp);
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}