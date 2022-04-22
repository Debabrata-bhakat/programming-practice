#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "Trie.h"

bool checkPalin(string word){
    for(int i=0; i<word.size()/2; i++){
        if(word[i]!=word[word.size()-i-1]) return false;
    }
    return true;
}


int main(){
    int n; cin >> n;
    Trie t;
    vector<string> a;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        a.push_back(s);
        reverse(s.begin(),s.end());
        t.insertWord(s);
    }
    for (int i = 0; i < a.size(); i++)
    {
        string curr_word = a[i];
        for (int i = 0; i < curr_word.size(); i++)
        {
            string firstWord = curr_word.substr(0,i);
            string secondWord = curr_word.substr(i);
            // if first word is not a palindrome then continue
            if (!checkPalin(firstWord)) continue;
            // if it is palindrome then check if the second word reverse is present or not
            if(t.search(secondWord)){
                cout << "true\n";
                return 1;
            }
        }
        
    }
    cout << "false\n";
}