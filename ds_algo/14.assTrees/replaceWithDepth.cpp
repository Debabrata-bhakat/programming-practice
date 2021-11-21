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
void printAns(TreeNode<int> *root){
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size()!=0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        for (int i = 0; i < front->children.size(); i++)
        {
            pendingNodes.push(front->children[i]);
            cout << front->children[i]->data << " ";
        }
        cout << endl;
    }
    
}

TreeNode<int> *replaceWithDepth(TreeNode<int> *root, int depth=0){
    // Edge case
    if(root==NULL) return 0;
    root->data = depth;
    for (int i = 0; i < root->children.size(); i++)
    {
        replaceWithDepth(root->children[i], depth+1);
    }
    return root;
}


int main(){
    TreeNode<int>*root = takeInputLevelWise();
    printLevelWise(root);
    root = replaceWithDepth(root);
    cout << root->data << endl;
    printAns(root);
}
