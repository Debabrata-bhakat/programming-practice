#include <iostream>
using namespace std;
#include "BinaryTreeNode.h"
#include <queue>
#include <stack>

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

void inOrder(BinaryTreeNode<int> *root){
    stack<BinaryTreeNode<int>*> inStack;
    BinaryTreeNode<int>* curr = root;
    while(curr!=NULL or inStack.size()!=0){
        while(curr!=NULL){
            inStack.push(curr);
            curr = curr->left;
        }
        curr = inStack.top();
        inStack.pop();
        cout << curr->data << endl;
        curr = curr->right;
    }
}

void revInorder(BinaryTreeNode<int> *root){
    stack<BinaryTreeNode<int>*> inStack;
    BinaryTreeNode<int> *curr = root;
    while(curr!=NULL or inStack.size()!=0){
        while (curr!=NULL)
        {
            inStack.push(curr);
            curr = curr->right;
        }
        curr = inStack.top();
        inStack.pop();
        cout << curr->data << endl;
        curr = curr->left;
    }
}

void pairSumBST(BinaryTreeNode<int>*root, int n){
    // if tree is empty
    if(root==NULL) return;
    stack<BinaryTreeNode<int>*> inStack, revStack;
    BinaryTreeNode<int> *in_curr = root;
    BinaryTreeNode<int> *rev_curr = root;
    while(in_curr!=NULL or inStack.size()!=0 ){
        // traverse for inorder stack
        while(in_curr!=NULL){
            inStack.push(in_curr);
            in_curr = in_curr->left;
        }
        in_curr = inStack.top();
        inStack.pop();
        // traverse for reverse inorder stack
        while(rev_curr!=NULL){
            revStack.push(rev_curr);
            rev_curr = rev_curr->right;
        }
        rev_curr = revStack.top();
        revStack.pop();
        // terminating condition
        if(in_curr->data >= rev_curr->data) return;
        // check if sum matches target
        if(in_curr->data + rev_curr->data ==n){
            cout << in_curr->data << " " << rev_curr->data << endl;
            in_curr = in_curr->right;
            rev_curr = rev_curr->left;
        }else if(in_curr->data + rev_curr->data > n){
            rev_curr = rev_curr->left;
        }else{
            in_curr = in_curr->right;
        }
    }
}

int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int n;
    cin >> n;
    pairSumBST(root, n);
}

