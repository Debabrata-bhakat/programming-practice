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
        else
        {
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

Node *insertNodeRec(Node *head, int i, int data){
    //Base case
    if (head==NULL and i!=0)
    {
        return head;
    }
    //Insert node at head
    if (i==0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }
        
    Node *a = insertNodeRec(head->next, i-1, data);
    head->next = a;
    return head;
    
}

int main(){
    Node *head = takeInput();
    // print(head);
    int data,i;
    cin >> i>> data;
    head = insertNodeRec(head, i, data);
    print(head);
}