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

Node *middleNode(Node *head){
    Node *slow = head;
    Node *fast = head->next;

    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *mergeSortLL(Node *head){
    // Base case
    if(head==NULL or head->next==NULL){
        return head;
    }
    // find middle node
    Node *middle = middleNode(head);
    // Merge the two small arrays
    Node *firstOutput = mergeSortLL(middle->next);
    //Make the last node null of the first part
    middle->next = NULL;
    Node *secondOutput = mergeSortLL(head);

    // Merge sort
    Node *res = mergeLL(firstOutput, secondOutput);
    return res;
}

void solve(){
    Node *head = takeInput();
    Node *res = mergeSortLL(head);
    print(res);
}