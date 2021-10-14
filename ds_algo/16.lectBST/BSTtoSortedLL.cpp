#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
#include "Node.h"
using namespace std;

BinaryTreeNode<int> *takeInputLevelWise(){
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;
    if(rootData == -1) return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of: " << front->data << endl;
        int leftData;
        cin >> leftData;
        if(leftData != -1){
            BinaryTreeNode<int> *left = new BinaryTreeNode<int>(leftData);
            front->left = left;
            pendingNodes.push(left);
        }   
        cout << "Enter right child of: " << front->data << endl;
        int rightData;
        cin >> rightData;
        if(rightData != -1){
            BinaryTreeNode<int> *right = new BinaryTreeNode<int>(rightData);
            front->right = right;
            pendingNodes.push(right);
        }
    }
    return root;
}


void printTreeLevelWise(BinaryTreeNode<int> *root){
    if(root==NULL) return;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ": ";
        if(front->left != NULL){
            cout << "L" << front->left->data;
            pendingNodes.push(front->left);
        }
        if(front->right != NULL){
            cout << "R" << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
    
}
void levelOrderTraversal(BinaryTreeNode<int> *root){
    if(root==NULL) return;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while (pendingNodes.size()!=0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if(front==NULL){
            cout << endl;
            if(pendingNodes.size()==0) break;
            else{
                pendingNodes.push(NULL);
                continue;
            } 
        }
        else cout << front->data << " ";
        if(front->left!=NULL) pendingNodes.push(front->left);
        if(front->right!=NULL) pendingNodes.push(front->right);
    }
    cout << endl;
}

class BSTtoSortedLLreturn{
    public:
    Node *head;
    Node *tail;
};

BSTtoSortedLLreturn BSTtoSortedLL(BinaryTreeNode<int> *root){
    if(root==NULL) {
        BSTtoSortedLLreturn temp;
        temp.head = NULL;
        temp.tail = NULL;
        return temp;
    }
    BSTtoSortedLLreturn left = BSTtoSortedLL(root->left);
    BSTtoSortedLLreturn right = BSTtoSortedLL(root->right);
    BSTtoSortedLLreturn output;
    Node *head = new Node(root->data);
    Node *tail = head;
    if(right.head!=NULL){
        tail = right.tail;
        head->next = right.head;
    }
    if(left.tail!=NULL){
        left.tail->next = head;
        head = left.head;
    }
    output.head = head;
    output.tail = tail;
    return output;  
}

int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    levelOrderTraversal(root);
    BSTtoSortedLLreturn output = BSTtoSortedLL(root);
    Node *temp = output.head;
    cout << "he\n" ;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}