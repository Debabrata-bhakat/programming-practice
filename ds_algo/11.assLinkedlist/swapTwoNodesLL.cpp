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

Node *swapLL(Node *head, int a, int b){
    Node *p1=NULL;
    Node *c1=head;
    Node *p2=NULL;
    Node *c2=head;
    Node *temp = head;
    int cout1 = 0;
    int cout2 = 0;
    while(c1!=NULL and cout1++!=a){
        p1 = c1;
        c1 = c1->next;
    }
    while(c2!=NULL and cout2++!=b){
        p2 = c2;
        c2 = c2->next;
    }



    if(p1!=NULL) p1->next = c2;
    else head = c2;
    if(p2!=NULL)  p2->next = c1;
    else head = c1;
    Node *t = c2->next;
    c2->next = c1->next;
    c1->next = t;
    return head;
}

void solve(){
    Node *head = takeInput();
    int a,b;
    cin >> a >> b;
    Node *res = swapLL(head, a, b);
    print(res);

}