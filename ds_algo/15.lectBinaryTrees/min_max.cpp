#include <iostream>
#include <queue>
#include <vector>
#include "BinaryTreeNode.h"
#include <climits>
using namespace std;


void printTree(BinaryTreeNode<int>*root){
    if(root==NULL) return;
    cout << root->data << ": ";
    if(root->left!=NULL) cout << "L" << root->left->data; 
    if(root->right!=NULL) cout << "R" << root->right->data;
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

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

BinaryTreeNode<int> *takeInput(){
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if(rootData==-1) return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
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

int numNodes(BinaryTreeNode<int> *root){
    if(root==NULL) return 0;
    return 1 + numNodes(root->left) + numNodes(root->right);
}

void inOrder(BinaryTreeNode<int> *root){
    if(root==NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(BinaryTreeNode<int> *root){
    if(root==NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BinaryTreeNode<int> *root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int height(BinaryTreeNode<int> *root){
    if(root==NULL) return 0;
    return 1 + max(height(root->left),height(root->right));
}

int diameter(BinaryTreeNode<int> *root){
    if(root==NULL) return 0;

    int option1 = height(root->left) + height(root->right) + 1;
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1, max(option2, option3));
}

pair<int,int> min_max_tree(BinaryTreeNode<int> *root){
    if(root==NULL){
        pair<int, int> p;
        p.first = INT_MAX;
        p.second = INT_MIN;
        return p;
    }

    pair<int,int> left = min_max_tree(root->left);
    pair<int, int> right = min_max_tree(root->right);
    pair<int, int> ans;
    ans.first = min(min(left.first, right.first), root->data);
    ans.second = max(max(left.second, right.second), root->data);
    return ans;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    pair<int, int> p = min_max_tree(root);
    cout << p.first << " " << p.second << endl;
    delete root;
}

