// https://leetcode.com/problems/word-ladder/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    class Word{
      public:
        string word;
        int dis;
        Word(){}
        Word(string word, int dis):word(word),dis(dis){}
    };
    bool isValid(string x, string y){
        int ans=0;
        for(int i=0;i<y.length();i++){
            if(x[i]!=y[i]) ans++;
            if(ans>1) return false;
        }
        if(ans==1) return true;
        return false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<Word> q;
        Word b(beginWord,1);
        q.push(b);
        while(!q.empty()){
            Word curr = q.front(); q.pop();
            // if(curr.word==endWord) return curr.dis;
            for(int i=0;i<wordList.size();i++){
                if(!isValid(curr.word,wordList[i])) continue;
                if(wordList[i]==endWord) return curr.dis+1;
                Word newWord(wordList[i],curr.dis+1);
                wordList.erase(wordList.begin()+i); i--;
                q.push(newWord);
            }
        }
        return 0;
    }
};
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string b,e; cin>>b>>e;
		int n; cin>>n;
		vector<string> lis;
		for (int i = 0; i < n; ++i)
		{
			string t; cin>>t;
			lis.push_back(t);
		}
		Solution obj;
		int ans = obj.ladderLength(b,e,lis);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends


/*
1
hit 
cog
6
hot dot dog lot log cog
*/