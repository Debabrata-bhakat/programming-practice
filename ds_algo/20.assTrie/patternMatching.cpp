#include <iostream>
using namespace std;
#include "Trie.h"

int main(){
    int n; cin >> n;
    Trie t;
    // t.insertWord("hell");
    // cout <<t.search("hell");
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        t.patternMatchInsert(s);
    }
    string find; cin >> find;
    cout << t.patternMatchingSearch(find) << endl;
    // cout << t.search("def") << endl;
}