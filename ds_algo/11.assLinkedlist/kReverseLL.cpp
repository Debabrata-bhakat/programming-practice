#include<bits/stdc++.h>
using namespace std;
#include "Node.cpp"

class Pair{
    public:
    Node *head;
    Node *tail;
};

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

Pair reverseLL(Node *head){
    // Base case
    if(head==NULL or head->next==NULL){
        Pair res;
        res.head = head;
        res.tail = head;
        return res;
    }
    Pair smallOutput = reverseLL(head->next);
    smallOutput.tail->next = head;
    head->next = NULL;
    Pair res;
    res.head = smallOutput.head;
    res.tail = head;
    return res; 

}

Node *kReverseLL(Node *head, int k){
    Node *temp = head;
    int c = 1;
    while(temp!=NULL){
        temp = temp->next;
    }
    // Base case
    if(c<=k){
        return reverseLL(head).head;
    }
    else{
        c = 1;
        temp = head;
        while (temp!=NULL and c++!=k)
        {
            temp = temp->next;
        }
        Node *temp2 = temp->next;
        temp->next = NULL;
        Pair rev = reverseLL(head);
        Node *smallOutput = kReverseLL(temp2,k);
        rev.tail->next = smallOutput;
        return rev.head;

    }
}

void solve(){
    Node *head = takeInput();
    int i;
    cin >> i;
    Node *res = kReverseLL(head,i);
    print(res);
}
