#include <iostream>
using namespace std;
#include "BinaryTreeNode.h"
#include <queue>
#include <climits>
#include <algorithm>
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

bool find(BinaryTreeNode<int> *node, int s){
    if(node==NULL) return false;
    if(node->data == s){
        cout << node->data << " ";
        node->data = INT_MIN;
        return true;
    }
    return find(node->left,s) or find(node->right, s);
}

void pairSum(BinaryTreeNode<int> *curr, int s, BinaryTreeNode<int> *root){
    if(curr==NULL or curr->data == INT_MIN) return;
    if(find(root, s - curr->data)){
        cout << curr->data << "\n";
        curr->data = INT_MIN;
    }
    pairSum(curr->left, s, root);
    pairSum(curr->right, s, root);
}

void treeToArray(BinaryTreeNode<int> *root, vector<int>& nodes){
    if(root==NULL) return;
    nodes.push_back(root->data);
    treeToArray(root->left, nodes);
    treeToArray(root->right, nodes);
}

void pairSum2(vector<int> nodes, int s){
    sort(nodes.begin(), nodes.end());
    int si=0,ei=nodes.size();
    while(si<=ei){
        if(nodes[si]+nodes[ei]==s){
            cout << nodes[si] << " " << nodes[ei] << "\n"; 
            si++;
            ei--;
        }else if(nodes[si]+nodes[ei]<s){
            si++;
        }else{
            ei--;
        }
    }
}

int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int s;
    cin >> s;
    // pairSum(root, s, root);
    vector<int> nodes;
    treeToArray(root, nodes);
    pairSum2(nodes, s);
}