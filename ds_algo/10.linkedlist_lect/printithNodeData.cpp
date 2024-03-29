#include<bits/stdc++.h>
using namespace std;
#include "Node.cpp"

void solve();
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}


Node *takeInput(){
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail ->next = newNode;
            tail = tail ->next;
        }
        cin >> data;
    }
    return head;
}

void solve(){
    Node *head = takeInput();
    int pos,c = 0;
    cin >> pos;
    Node *temp = head;
    while (temp!=NULL)
    {
        if(pos == c){
            cout << temp ->data << '\n';
            return;
        }
        c++;
        temp = temp ->next;
    }
    cout << "-1\n";
}