#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    unordered_map<string,int> ourmap;
    // insert
    pair<string,int> p("abc",1);
    ourmap.insert(p);
    ourmap["def"] = 2;

    // find or access
    cout << ourmap["abc"] << endl;
    cout << ourmap.at("abc") << endl;
    // cout << ourmap.at("ghi") << endl;   -------------- throws an error
    cout << "size: " << ourmap.size() << endl;
    cout << ourmap["ghi"] << endl;      //-------------- does not throw error; inserts the default value 0 and prints it
    cout << "size: " << ourmap.size() << endl;

    // check presence
    if(ourmap.count("ghi")>0){
        cout << "ghi is present\n";
    }

    // erase
    ourmap.erase("ghi");
    if(ourmap.count("ghi")>0){
        cout << "ghi is present\n";
    }
    cout << "size: " << ourmap.size() << endl;
}