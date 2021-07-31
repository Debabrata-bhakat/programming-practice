#include <iostream>
using namespace std;
#include "Node.cpp"

Node *takeInput(){
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data!=-1)
    {
        Node *newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            tail = newNode;
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
       cout << temp->data << " ";
       temp = temp->next; 
    }
   cout << '\n'; 
}

int find(Node *head, int num){
    Node *temp = head;
    int c=0;
    while (temp!=NULL)
    {
       if (temp->data==num)
       {
           return c;
       }
       c++;
       temp = temp->next; 
    }
   return -1; 
}

int main(){
    Node *head = takeInput();
    print(head);
    int i;
    cin>>i;
    cout << find(head, i) << '\n';
}