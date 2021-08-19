#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

class Pair{
    public:
    int data;
    TreeNode<int> *node;
};

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

Pair maxSum(TreeNode<int> *root){
    Pair ans;
    ans.data = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans.data += root->children[i]->data;
    }
    ans.node = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        Pair temp = maxSum(root->children[i]);
        if(temp.data > ans.data){
            ans.data = temp.data;
            ans.node = temp.node;
        }
    }
    return ans;
    
}

int main(){
    TreeNode<int>*root = takeInputLevelWise();
    printLevelWise(root);
    Pair ans = maxSum(root);
    cout << ans.node->data << endl;
}