#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *takeInputLevelWise(){
    int data;
    cout << "Enter data for root node: ";
    cin >> data;
    queue<TreeNode<int> *> pendingNodes;
    TreeNode<int> *root = new TreeNode<int>(data);
    pendingNodes.push(root);
    while (pendingNodes.size()!=0)
    {   
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter data for " << i << "th child" << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
        
    }
    return root;
}

void printLevelWise(TreeNode<int> *root){
    // Edge case 
    if(root==NULL) return;
    queue<TreeNode<int> *> pendingNodes;
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

int heightOfTree(TreeNode<int> *root){
    int numChild = root->children.size();
    int max=0;
    for (int i = 0; i < numChild; i++)
    {
        int temp = heightOfTree(root->children[i]);
        if(temp>max) max = temp;
    }
    return max+1;
}

int main(){
    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    cout << heightOfTree(root) << endl;
}