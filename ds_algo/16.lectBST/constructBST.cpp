#include <iostream>
#include <vector>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* constructBST(vector<int> arr, int si, int ei){
    if(si>ei) return NULL;
    int mid = (si+ei)/2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);
    BinaryTreeNode<int> *left = constructBST(arr, si, mid-1);
    BinaryTreeNode<int> *right = constructBST(arr, mid+1, ei);
    root->left = left;
    root->right = right;
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
void preOrder(BinaryTreeNode<int> *root){
    if(root==NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
int main(){
    vector<int> input_array = {1,2,3,4,5,6,7};
    BinaryTreeNode<int> *root = constructBST(input_array, 0, input_array.size()-1);
    levelOrderTraversal(root);
    preOrder(root);
}