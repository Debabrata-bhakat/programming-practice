#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
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

int height(BinaryTreeNode<int> *root){
    if(root==NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool checkBalancedTree(BinaryTreeNode<int> *root){
    if(root==NULL) return true;
    int lh=0, rh=0;
    if(root->left!=NULL){
        lh = height(root->left);
    }
    if(root->right!=NULL){
        rh = height(root->right);
    }
    return checkBalancedTree(root->left) and checkBalancedTree(root->right) and (abs(lh-rh) <= 1);
}

pair<bool, int> betterCheck(BinaryTreeNode<int> *root){
    // Base case
    if(root==NULL){
        pair<bool,int> p;
        p.first = true;
        p.second = 0;
        return p;
    }
    pair<bool, int> leftAns = betterCheck(root->left);
    pair<bool, int> rightAns = betterCheck(root->right);
    pair<bool, int> p;
    p.second = 1 + max( leftAns.second, rightAns.second );
    p.first = leftAns.first and rightAns.first and (abs( leftAns.second - rightAns.second ) <= 1);
    return p;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    // printTreeLevelWise(root);
    cout << checkBalancedTree(root) << endl;
    cout << betterCheck(root).first << endl;
}


