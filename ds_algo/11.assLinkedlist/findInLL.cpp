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
    while (data!=-1)
    {
        Node *newNode = new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

int findIndex(Node *head, int s){
    Node *temp = head;
    int in = 0;
    while(temp!=NULL and temp->data!=s){
        temp = temp->next;
        in++;
    }
    if(temp==NULL) return -1;
    else return in;
}

void solve(){
    Node *head = takeInput();
    int s;
    cin >> s;
    cout << findIndex(head, s) <<'\n';
}
