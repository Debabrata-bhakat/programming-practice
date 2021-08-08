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
    while (temp != NULL)
    {
        cout << temp ->data << " " ;
        temp = temp ->next;
    }
    
}

Node *evenAfterOdd(Node *head){
    Node *oh=NULL;
    Node *ot=NULL;
    Node *eh=NULL;
    Node *et=NULL;
    while(head!=NULL){
        if(head->data%2==1){
            if(oh==NULL){
                oh = head;
                ot = head;
            }
            else{
                ot->next = head;
                ot = ot->next;
            }
        }
        else{
            if(eh==NULL){
                eh = head;
                et = head;
            }
            else{
                et ->next = head;
                et = et ->next;
            }
        }
        head = head->next;
    }

    if(et!=NULL) et->next=NULL;
    if(ot!=NULL){
        ot->next = eh;  
        return oh;
    } 
    else{
        return eh;
    }

}

void solve(){
    Node *head = takeInput();
    Node *res = evenAfterOdd(head);
    print(res);
    cout << '\n';
}