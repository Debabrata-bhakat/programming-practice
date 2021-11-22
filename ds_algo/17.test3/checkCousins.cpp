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

pair<int,BinaryTreeNode<int>*> depthOfNode(BinaryTreeNode<int> *root, int target){
    // if tree is empty
    if(root==NULL){
        pair<int,BinaryTreeNode<int>*> res;
        res.first = -1;
        res.second = NULL;
        return res;
    }
    if(root->data==target) {
        pair<int, BinaryTreeNode<int>*> res;
        res.first = 0;
        res.second = NULL;
        return res;
    }
    int depth = -1;
    pair<int,BinaryTreeNode<int>*> right_depth = depthOfNode(root->right, target);
    pair<int,BinaryTreeNode<int>*> left_depth = depthOfNode(root->left, target);
    // if node is not found in any of the subtrees then return -1
    if(right_depth.first==-1 and left_depth.first==-1) {
        pair<int,BinaryTreeNode<int>*> res;
        res.first = -1;
        res.second = root;
        return res;
    }
    else {
        pair<int,BinaryTreeNode<int>*> res;
        res.first = max(right_depth.first,left_depth.first)+1;
        if(res.first==1) res.second = root;
        else if (right_depth.first +1 == res.first) res.second = right_depth.second;
        else res.second = left_depth.second;
        return res;
    }
}

int main(){
    BinaryTreeNode<int> *root;
    root =  takeInputLevelWise();
    // cout << depthOfNode(root,9).first << " " << depthOfNode(root,9).second->data << endl;
    int a,b;
    cin >> a >> b;
    pair<int,BinaryTreeNode<int>*> a_depth = depthOfNode(root,a);
    pair<int, BinaryTreeNode<int>*> b_depth = depthOfNode(root,b);
    // if depth matches and parent do not match, then they are cousins
    if(a_depth.first==b_depth.first and a_depth.second!=b_depth.second) cout << "true\n";
    else cout << "false\n";
}