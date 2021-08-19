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

bool identical(TreeNode<int> *root1, TreeNode<int> *root2){
    if(root1->data!=root2->data or root1->children.size()!=root1->children.size()) return false;
    for (int i = 0; i < root1->children.size(); i++)
    {
        if(!identical(root1->children[i], root2->children[i])) return false; 
    }
    return true;
}

int main(){
    TreeNode<int>*root1 = takeInputLevelWise();
    printLevelWise(root1);
    TreeNode<int>*root2 = takeInputLevelWise();
    printLevelWise(root2);
    cout << identical(root1, root2) << endl;
}