#include <iostream>
#include <vector>
using namespace std;


int main(){
    // Dynamic allocation
    // vector<int> *vp = new vector<int>();
    vector<int> v;
    for (int i = 0; i < 100; i++)
    {
        v.push_back(i+1);
        cout << "Cap: " << v.capacity() << endl;
        cout << "Size: " << v.size() << endl;
    }
    

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v[1] = 100;
    // dont use this for inserting elements
    // v[3] = 1002;
    // v[4] = 1234;

    v.push_back(23);
    v.push_back(234);
    v.pop_back();

    for (int i = 0; i < v.size(); i++)
    {
        // cout << v[i] << endl;
        // v.at(index) is better than[]
    }
    

    // cout << v[0] << endl;
    // cout << v[1] << endl;
    // cout << v[2] << endl;

}