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

Node *mergeLL(Node *head1, Node *head2){
    // Approach similar to takeInput
    Node *temp_head=NULL;
    Node *temp_tail=NULL;
    if(head1->data <= head2->data) {
        temp_head = head1;
        temp_tail = head1;
        head1 = head1->next;
    }
    else{
        temp_head = head2;
        temp_tail = head2;
        head2 = head2->next;
    }
    while(head1!=NULL and head2!=NULL){
        if(head1->data <= head2->data){
            temp_tail->next = head1;
            temp_tail = temp_tail->next;
            head1 = head1->next;
        }
        else{
            temp_tail->next = head2;
            temp_tail = temp_tail ->next;
            head2 = head2->next;
        }
    }
    if(head2!=NULL){
        temp_tail->next = head2;
    }
    else{
        temp_tail->next = head1;
    }
    return temp_head;
}


void solve(){
    Node *head1 = takeInput();
    print(head1);
    Node *head2 = takeInput();
    print(head2);
        

    Node *temp_head = mergeLL(head1, head2);
    print(temp_head);
}