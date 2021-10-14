#include <iostream>
using namespace std;
#include "BinaryTreeNode.h"
#include <queue>
#include <climits>

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

class outputLargestBST{
    public:
        int min;
        int max;
        int height;
        bool isBST;
};

outputLargestBST largestBST(BinaryTreeNode<int> *root){
    if(root==NULL){
        outputLargestBST output;
        output.min = INT_MAX;
        output.max = INT_MIN;
        output.height = 0;
        output.isBST = true;
        return output;
    }
    outputLargestBST left = largestBST(root->left);
    outputLargestBST right = largestBST(root->right);
    outputLargestBST output;
    output.min = min(left.min, min(right.min, root->data));
    output.max = max(left.max, max(right.max, root->data));
    if(left.isBST==true and right.isBST==true){
        if(left.max < root->data and right.min > root->data){
            output.isBST = true;
            output.height = max(left.height,right.height) + 1;
            return output;
        }else{
            output.isBST = false;
            output.height = max(left.height, right.height);
            return output;
        }
    }else{
        output.isBST = false;
        output.height = max(left.height, right.height);
        return output;
    }
}

int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << largestBST(root).height << endl;
}
