#include <iostream>
using namespace std;
#include "BinaryTreeNode.h"
#include <queue>

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

void printNodesKDistDown(BinaryTreeNode<int> *root, int k){
    if(root==NULL or k<0) return;
    if(k==0){
        cout << root->data << " \n";
    }
    printNodesKDistDown(root->left, k-1);
    printNodesKDistDown(root->right, k-1);
}

int printNodesAtDistK(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node, int k){
    // Base case
    if(root==NULL) return -1;
    // if target is found
    if(root==node){
        printNodesKDistDown(root, k);
        return 0;
    }
    // left subtree
    int ld = printNodesAtDistK(root->left, node, k);
    if(ld!=-1){
        if(ld+1 == k){
            cout << root->data << " ";
        }
        else{
            printNodesKDistDown(root->right, k-ld-2);
        }
        return 1+ld;
    }// right subtree
    int rd = printNodesAtDistK(root->right, node, k);
    if(rd!=-1){
        if(rd+1==k)
        cout << root->data << " \n";
        else printNodesKDistDown(root->left, k-rd-2);
        return rd+1;
    }
    return -1;
}
int printNodesAtDistK(BinaryTreeNode<int> *root, int node, int k){
    // Base case
    if(root==NULL) return -1;
    // if target is found
    if(root->data==node){
        printNodesKDistDown(root, k);
        return 0;
    }
    // left subtree
    int ld = printNodesAtDistK(root->left, node, k);
    if(ld!=-1){
        if(ld+1 == k){
            cout << root->data << "\n ";
        }
        else{
            printNodesKDistDown(root->right, k-ld-2);
        }
        return 1+ld;
    }// right subtree
    int rd = printNodesAtDistK(root->right, node, k);
    if(rd!=-1){
        if(rd+1==k)
        cout << root->data << "\n ";
        else printNodesKDistDown(root->left, k-rd-2);
        return rd+1;
    }
    return -1;
}

int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int node, k;
    cin >> node >> k;
    printNodesAtDistK(root, node, k);
}