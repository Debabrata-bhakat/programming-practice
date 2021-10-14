#include <iostream>
#include <queue>
#include <vector>
#include "BinaryTreeNode.h"
using namespace std;

class Pair{
    public:
    int height;
    int diameter;
};

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

Pair height_diameter(BinaryTreeNode<int> *root){
    if(root==NULL) {
        Pair temp;
        temp.height = 0;
        temp.diameter = 0;
        return temp;
    }
    Pair left = height_diameter(root->left);
    Pair right = height_diameter(root->right);

    Pair temp;
    temp.height = 1 + max(left.height, right.height);
    int option1 = left.height + right.height;
    int option2 = left.diameter;
    int option3 = right.diameter;
    temp.diameter = max(option1, max(option2, option3));
    return temp;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    Pair p = height_diameter(root);
    cout << "Height: " << p.height << endl;
    cout << "Diameter: " << p.diameter << endl;
    delete root;
}

