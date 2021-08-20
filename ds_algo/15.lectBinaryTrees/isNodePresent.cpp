#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;


void printTreeLevelWise(BinaryTreeNode<int> *root){
    if(root==NULL) return;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size()!=0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ": ";
        if(front->left!=NULL){
            cout << "L" << front->left->data;
            pendingNodes.push(front->left);
        }
        if(front->right!=NULL){
            cout << "R" << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
    
}


BinaryTreeNode<int> *takeInputLevelWise(){
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if(rootData==-1) return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size()!=0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if(leftChildData!=-1){
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if(rightChildData!=-1){
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

bool isNodePresent(BinaryTreeNode<int> *root, int search){
    if(root==NULL) return false;
    return (root->data==search) or isNodePresent(root->right, search) or isNodePresent(root->left, search);
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    // printTreeLevelWise(root);
    int search;
    cin >> search;
    cout << isNodePresent(root, search) << endl;
    delete root;
}
