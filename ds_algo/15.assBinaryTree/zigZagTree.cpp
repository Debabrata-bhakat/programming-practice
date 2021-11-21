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

void zigzag(BinaryTreeNode<int> *root){
    if(root==NULL) return;
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    vector<int> pendingData;
    int odd = 1;
    while (pendingNodes.size()!=0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if(front==NULL){
            if(odd==1){
                for (int i = 0; i < pendingData.size(); i++)
                {
                    cout << pendingData[i] << " ";
                }
            }
            else{
                for (int i = pendingData.size()-1; i >= 0 ; i--)
                {
                    cout << pendingData[i] << " ";
                }
            }
            odd *= -1;
            cout << endl;
            pendingData.clear();
            if(pendingNodes.size()==0) break;
            pendingNodes.push(NULL);
        }
        else{
            pendingData.push_back(front->data);
            if(front->left!=NULL){
                pendingNodes.push(front->left);
            }
            if(front->right!=NULL){
                pendingNodes.push(front->right);
            }
        }
    }
    
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    zigzag(root);
}


