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

BinaryTreeNode<int> *mirrorBinaryTree(BinaryTreeNode<int> *root){
    if(root==NULL) return NULL;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    //interchange the left and right child
    BinaryTreeNode<int> *temp = root->right;
    root->right = root->left;
    root->left = temp;
    return root;

}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    root = mirrorBinaryTree(root);
    printTreeLevelWise(root);
    delete root;
}
