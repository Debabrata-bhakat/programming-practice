#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> ourmap;
    ourmap["abc"] = 1;
    ourmap["abc1"] = 2;
    ourmap["abc2"] = 3;
    ourmap["abc3"] = 4;
    ourmap["abc4"] = 5;
    ourmap["abc5"] = 6;
    unordered_map<string,int>::iterator it = ourmap.begin();
    while(it!=ourmap.end()){
        cout << "Key: " << it->first << " Value: " << it->second << endl;
        it++;
    }

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    vector<int>::iterator it1 = v.begin();
    while(it1!=v.end()){
        cout << *it1 << endl;
        it1++;
    }

    //find
    unordered_map<string,int>::iterator it2 = ourmap.find("abc");
    v.erase(it1,it1+4);
}