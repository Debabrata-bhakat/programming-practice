#include <iostream>
#include <vector>
using namespace std;
#include "Trie.h"

int main(){
    int n; cin >> n;
    Trie t;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        t.insertWord(s);
    }
    string s; cin >> s;
    vector<string> words = t.autoComplete(s);
    for (int i = 0; i < words.size(); i++)
    {
        cout << s + words[i].substr(1) << endl;
    }
        
}