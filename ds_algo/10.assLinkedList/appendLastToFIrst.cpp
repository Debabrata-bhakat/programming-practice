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
        if (head==NULL)
        {
            head=newNode;
            tail=newNode;   
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;        
    }
    return head;
}

int printAndLen(Node *head){
    Node *temp = head;
    int count = 0;
    while (temp!=NULL)
    {
        cout << temp->data << " ";
        count++;
        temp = temp->next;
    }
    cout << '\n';
    return count;
}

Node *appendLastToFirst(int in, Node *head){
    int count = 0;
    Node *temp = head;
    Node *a = NULL;
    Node *b = NULL;
    while (temp!=NULL)
    {
        if(in==count){
            a = temp;
        }
        if(temp->next==NULL){
            b = temp;
        }
        temp = temp->next;
        count++;
    }
    b->next = head;
    head = a->next;
    a->next = NULL;
    return head;
}


void solve(){
    Node *head = takeInput();
    int len = printAndLen(head);
    int i; 
    cin >> i;
    int in = len-i-1;
    head = appendLastToFirst(in, head);
    printAndLen(head);
}