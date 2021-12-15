#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


void longest(vector<int> a){
    int max = a[0];
    for (int i = 0; i < a.size(); i++)
    {
        if(max<a[i]) max = a[i];
    }
    int *seen = new int[max+1];
    for (int i = 0; i < max+1; i++)
    {
        seen[i] = 0;
    }
    
    for (int i = 0; i < a.size(); i++)
    {
        seen[a[i]] = 1;
    }
    int len_max = 1;
    int s=a[0], e=a[0];
    for (int i = 0; i < max+1; i++)
    {
        if(seen[i]==0) continue;
        int temp1 = i, temp2 = i,c = 1;
        i++;
        while(seen[i]!=0){
            temp2 = i;
            c++;
            i++;
        }
        if(len_max<c){
            len_max = c;
            s = temp1;
            e = temp2;
        }
    }
    cout << s << " " << e << endl;
}

void longest_hashmap(vector<int> a){
    unordered_map<int, bool> seen;
    for (int i = 0; i < a.size(); i++)
    {
        seen[a[i]] = true;
    }
    int si=a[0],ei=a[0],max = 1;
    unordered_map<int,bool>::iterator it = seen.begin();
    while(it!=seen.end()){
        if(it->second == false){
            it++;
            continue;
        }
        int curr = it->first;
        it->second = false;
        // look for forward elements
        int s = curr;
        int e = curr;
        int size = 1;
        while(true){
            // check for presence
            if(seen.count(e+1)>0){
                seen[e+1] = false;
                e++;
                size++;
            }else break;
        }
        // look for backward elements
        while(true){
            // check for presence
            if(seen.count(s-1)>0){
                seen[s-1] = false;
                s--;
                size++;
            }else break;
        }
        if(max<size){
            max = size;
            si = s;
            ei = e;
        }
        it++;
    }
    cout << si << " " << ei << endl;
}

int main(){
    int n; cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int t; cin >> t;
        a.push_back(t);
    }
    longest_hashmap(a);
}