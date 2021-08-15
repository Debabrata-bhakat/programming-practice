#include <iostream>
#include "Node.h"
using namespace std;

Node *takeInput(){
    int data;
    cin >> data;
    Node *head=NULL;
    Node *tail=NULL;
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
    cout << endl;
}

Node *solve(Node *head){
    Node *start=NULL;
    Node *temp = head;
    while (temp->next!=NULL)
    {
        if(temp->next->data==9 and start==NULL){
            start = temp;
        }
        else if(temp->next->data != 9){
            start = NULL;
        }
        temp = temp->next;
    }
    if(start==NULL){
        temp->data += 1;
        return head;
    }
    if(start == head and head->data == 9){
        Node *temp = head;
        while (temp!=NULL)
        {
            temp->data = 0;
            temp = temp->next;
        }
        Node *newNode = new Node(1);
        newNode ->next = head;
        head = newNode;
        return head;
    }
    else{
        Node *temp = start->next;
        start->data += 1;
        while (temp!=NULL)
        {
            temp->data = 9;
            temp = temp->next;
        }
        return head;
    }
}

int main(){
    Node *head = takeInput();
    print(head);
    Node *res = solve(head);
    print(res);
}