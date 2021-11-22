#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *takeInputLevelWise(){
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size()!=0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout << "Enter number of children of " << front->data << endl;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            cout << "Enter " << i << " th node of " << front->data << endl;
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
        
    }
    return root;
}

void printLevelWise(TreeNode<int> *root){
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size()!=0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ": ";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << " ";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
        
    }
    
}

TreeNode<int>* removeLeaf(TreeNode<int> *root){
    // if tree is empty
    if(root==NULL) return NULL;
    // if root is leaf
    if(root->children.size()==0) return NULL;
    for (int i = 0; i < root->children.size(); i++)
    {
        root->children[i] = removeLeaf(root->children[i]);
    }
    vector<TreeNode<int>*> temp;
    int c=0;
    // remove all NULL values
    for (int i = 0; i < root->children.size(); i++)
    {
        if(root->children[i]!=NULL) {
            temp.push_back(root->children[i]);
            c++;
        }
    }
    root->children = temp;
    return root;
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    root = removeLeaf(root);
    printLevelWise(root);
}