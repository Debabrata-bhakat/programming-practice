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

TreeNode<int> *nextLargest(TreeNode<int> *root, int s){
    int min=INT16_MAX;
    TreeNode<int> *ans = NULL;
    if(root->data > s and root->data < min){
        min = root->data;        
        ans = root;
    } 
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *temp = nextLargest(root->children[i], s);
        if(temp!=NULL and temp->data < min) {
            min = temp->data;
            ans = temp;
        }
    }
    return ans;
}

int main(){
    int s;
    cin >> s;
    TreeNode<int>*root = takeInputLevelWise();
    printLevelWise(root);
    TreeNode<int> *ans = nextLargest(root, s);
    cout << ans->data << endl;
}