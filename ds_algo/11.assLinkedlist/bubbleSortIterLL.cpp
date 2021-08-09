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

Node *bubbleSortLL(Node *head){
    // Find length
    Node *temp = head;
    int count = 0;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    for (int i = 0; i < count-1; i++)
    {
        temp = head;
        Node *p = NULL;
        Node *c = head;
        Node *n = head->next;
        while(c->next!=NULL){
            if(c->data<=n->data){
                p = c;
                c = n;
                n = n->next;
            }
            else if(p==NULL){
                c->next = n->next;
                n->next = c;
                // Update
                p = n;
                n = n->next->next;
                //change head
                head = p;
            }
            else{
                p->next = n;
                c->next = n->next;
                n->next = c;
                // Update
                p = p->next;
                n = n->next->next;
            }
        }
        
    }
    return head;
    
}

void solve(){
    Node *head = takeInput();
    Node *res = bubbleSortLL(head);
    print(res);
}