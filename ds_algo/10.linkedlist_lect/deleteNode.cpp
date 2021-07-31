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

void print(Node *head){
    Node *temp = head;
    while (temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp ->next;
    }
    cout << '\n';
}

Node *takeInput(){
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;\
    while (data!=-1)
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

Node *deleteNode(Node *head, int i){
    Node *temp = head;
    int count = 0;
    //First node delete
    if (i==0)
    {
        Node *a = head;
        head = head ->next;
        delete a;
        return head;
    }
    
    while (temp!=NULL and count<i-1)
    {
        temp = temp->next;
        count++;
    }
    if (temp!=NULL)
    {
        Node *a = temp->next;
        temp ->next = a ->next;
        delete a;
    }
    return head;
    
}

void solve(){
    Node *head = takeInput();
    // print(head);
    int i;
    cin >> i;
    head = deleteNode(head, i);
    print(head);
}