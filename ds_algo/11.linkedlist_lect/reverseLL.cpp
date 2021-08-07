#include <iostream>
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
    while (temp!=NULL)
    {
        cout << temp ->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}

Pair reverseLL_2(Node *head){
    // Base case
    if(head==NULL or head->next==NULL){
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }

    Pair smallAns = reverseLL_2(head->next);
    smallAns.tail->next = head;
    head->next=NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}

Node *reverseLL_better(Node *head){
    return reverseLL_2(head).head;
}

Node *reverseLL_3(Node *head){
    // Base case
    if(head==NULL or head->next==NULL){
        return head;
    }

    Node *smallOutput = reverseLL_3(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return smallOutput;

}
Node *reverseLL(Node *head){
    // Base case
    if(head==NULL or head->next==NULL){
        return head;
    }

    Node *smallOutput = reverseLL(head->next);
    Node *temp = smallOutput;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallOutput;

}

void solve(){
    Node *head = takeInput();
    Node *res = reverseLL(head);
    print(res);
    Node *res2 = reverseLL_better(head);
    print(res2);
    Node *res3 = reverseLL_3(head);
    print(res3);
}