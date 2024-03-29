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
        if (head==NULL)
        {
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
        temp = temp ->next;
    }
    cout << '\n';
}

Node *delRec(Node *head, int i){
    //Base case
    if (head==NULL)
    {
        return head;
    }
    if (i==0)
    {
        Node *a = head->next;
        delete head;
        return a;
    }
    Node *a = delRec(head->next, i-1);
    head->next = a;
    return head;
    
    
}

int main(){
    Node *head = takeInput();
    // print(head);
    int i;
    cin >> i;
    head = delRec(head,i);
    print(head);
}