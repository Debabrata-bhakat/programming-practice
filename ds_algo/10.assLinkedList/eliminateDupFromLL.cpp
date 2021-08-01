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

void print(Node *head){
    Node *temp = head;
    while (temp!=NULL)
    {
        cout << temp ->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}

void eliminateDup(Node *head){
    Node *temp = head->next;
    int curr = head->data;
    Node *curr_temp = head;
    while (temp!=NULL)
    {
        if(curr == temp->data){
            curr_temp->next = temp->next;
        }
        else
        {
            curr = temp->data;
            curr_temp = temp;
        }
        temp = temp->next;
    }
    
}

void solve(){
    Node *head = takeInput();
    // print(head);
    eliminateDup(head);
    print(head);
}