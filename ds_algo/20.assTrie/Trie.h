#include "TrieNode.h"
#include <string>

using namespace std;
class Trie{
    TrieNode *root;

    public:

    Trie(){
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode *root, string word){
        // Base case
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }

    // For user
    void insertWord(string word){
        insertWord(root, word);
    }

    bool search(TrieNode *root, string word){
        //Base case
        if(word.size() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
        } 
        else{
            return false;
        }
        return search(child, word.substr(1));
    }

    // For user
    bool search(string word){
        return search(root, word);
    }



    void removeWord(TrieNode *root, string word){
        // Base case
        if(word.size() == 0){
            root->isTerminal = false;
            return;
        }

        // Small calculation
        TrieNode *child;
        int index = word[0] - 'a';
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            // Word not found
            return;
        }

        removeWord(child, word.substr(1));

        // Remove child node if it is useless
        if(child->isTerminal == false){
            for (int i = 0; i < 26; i++)
            {
                if(child->children[i] != NULL){
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }

    // For user
    void removeWord(string word){
        removeWord(root, word);
    }



    ///////////////////////////////// PATTERN MATCHING//////////////////////
    bool patternMatchingSearch(TrieNode *root, string word){
        //Base case
        if(word.size() == 0){
            return true;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
        } 
        else{
            return false;
        }
        bool smallOutput = patternMatchingSearch(child, word.substr(1));
        return smallOutput;
    }

    // for user
    bool patternMatchingSearch(string word){
        return patternMatchingSearch(root, word);
    }

    void patternMatchInsert(string word){
        for (int i = 0; i < word.length(); i++)
        {
            // cout << word.substr(i) << endl;
            insertWord(word.substr(i));
        }
        
    }

    ///////////////////////////// AUTO COMPLETE ////////////////////
    TrieNode *getStartingNode(TrieNode *root, string word){
        // Base case
        if(word.size() == 0){
            return root;
        } 

        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }else{
            return NULL;
        }
        return getStartingNode(child, word.substr(1));
    }
    // for user
    TrieNode *getStartingNode(string word){
        return getStartingNode(root, word);
    }

    vector<string> allWords(TrieNode *root){
        vector<string> words;
        // add the current character to the array if it is a terminal
        if(root->isTerminal) words.push_back("");
        // get all words of the child nodes
        for (int i = 0; i < 26; i++)
        {
            if(root->children[i]==NULL) continue;
            vector<string> b = allWords(root->children[i]);
            words.insert(words.end(), b.begin(), b.end());
        }
        // add the character of root to every word
        for (int i = 0; i < words.size(); i++)
        {
            words[i] = root->data + words[i];
        }
        // if words array is empty then add the current letter
        if(words.size()==0){
            string s(1, root->data);
            words.push_back(s);
        }
        return words;
    }

    vector<string> autoComplete(string word){
        TrieNode *startNode = getStartingNode(word);
        // if the string does not match then return an empty vector
        vector<string> emptyVector;
        if(startNode==NULL) return emptyVector;
        return allWords(startNode);
    }

};
