#include <iostream>
#include <queue>
#include <vector>
#include "BinaryTreeNode.h"
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

BinaryTreeNode<int> *buildTree(int *in, int *pr, int inS, int inE, int preS, int preE){
    if(inS>inE){
        return NULL;
    cout << "hhell\n";
    }
    int lins, line, lpres, lpree, rins, rine, rpres, rpree;
    lins = inS;
    int rootData = pr[preS];
    int root_pos = -1;
    for (int i = inS; i <= inE; i++)
    {
        if(in[i] == rootData){
            root_pos = i;
            break;  
        } 
    }
    line = root_pos-1;
    lpres = preS + 1;
    int left_size = line - lins + 1;
    lpree = line - lins + lpres;

    rpree = preE;
    rpres = lpree + 1;
    rine = inE;
    rins = root_pos+1;


    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTree(in, pr, lins, line, lpres, lpree);
    root->right = buildTree(in, pr, rins, rine, rpres, rpree);
    return root;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
int main(){
    /*BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    root->left = node1;
    root->right = node2;*/
    // BinaryTreeNode<int> *root = takeInputLevelWise();
    // printTreeLevelWise(root);
    // delete root;
    // int in[] = {4,2,5,1,8,6,9,3,7};
    // int pre[] = {1,2,4,5,3,6,8,9,7};
    int in[] = {2,1,3};
    int pre[] = {1,2,3};
    BinaryTreeNode<int> *root = buildTree(in, pre, 0, 2,0,2);
    printTreeLevelWise(root);
}
