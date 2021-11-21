#include <iostream>
#include <queue>
#include <climits>
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

class IsBSTReturn{
    public:
        bool isBST;
        int minimum;
        int maximum;
};

IsBSTReturn isBST(BinaryTreeNode<int> *root){
    if(root==NULL){
        IsBSTReturn output;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        output.isBST = true;
        return output;
    }
    IsBSTReturn leftOut = isBST(root->left);
    IsBSTReturn rightOut = isBST(root->right);
    int minimum = min(root->data,min(leftOut.minimum, rightOut.minimum));
    int maximum = max(root->data, max(leftOut.maximum, leftOut.maximum));
    bool isBSTFinal = (root->data>leftOut.maximum) and (root->data<rightOut.minimum) and leftOut.isBST and rightOut.isBST;
    IsBSTReturn output;
    output.maximum = maximum;
    output.minimum = minimum;
    output.isBST = isBSTFinal;
    return output;
}

bool isBST3(BinaryTreeNode<int> *root, int min=INT_MIN, int max=INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data<min or root->data>max) return false;
    bool isLeftOK = isBST3(root->left, min, root->data-1);
    bool isRightOK = isBST3(root->right, root->data, max);
    return isLeftOK and isRightOK;
}

vector<int>* getRootToNodePath(BinaryTreeNode<int> *root, int data){
    if(root==NULL) return NULL;
    if(root->data == data) {
        vector<int> *output = new vector<int> ();
        output->push_back(root->data);  
        return output;
    }
    vector<int> *leftOutput = getRootToNodePath(root->left, data);
    if(leftOutput!=NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int> *rightOutput = getRootToNodePath(root->right, data);
    if(rightOutput!=NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }else{
        return NULL;
    }
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1 
// 4 2 6 1 30 5 7 -1 -1 -1 -1 -1 -1 -1 -1 

int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int data;
    cin >> data;
    vector<int> *output = getRootToNodePath(root, data);
    for (int i = 0; i < output->size(); i++)
    {
        cout << output->at(i) << " ";
    }
    cout << '\n';
    delete output;
    delete root;
}
