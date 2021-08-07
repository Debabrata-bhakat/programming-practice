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

int main(){
    Node *head = takeInput();
    print(head);
    Node *slow = head;
    Node *fast = head->next;

    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << '\n';
}