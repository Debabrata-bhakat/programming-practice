#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

class Pair{
    public:
    TreeNode<int> *max;
    TreeNode<int> *secondMax;
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

TreeNode<int> *helpSecondMax(TreeNode<int> *root1, TreeNode<int> *root2, TreeNode<int> *root3){

}

Pair secondLargest(TreeNode<int> *root){
    Pair ans;
    ans.max = root;
    ans.secondMax = NULL;
    for (int i = 0; i < root->children.size(); i++)
    {
        Pair smallOutput = secondLargest(root->children[i]);
        // case 1: both smallMax are null
        if(ans.secondMax==NULL and smallOutput.secondMax==NULL){
            if(ans.max->data > smallOutput.max->data) ans.secondMax = smallOutput.max;
            else{
                ans.secondMax = ans.max;
                ans.max = smallOutput.max;
            }  
        }

        //case 2: secondMax of smallOutput  is null
        else if(smallOutput.secondMax==NULL){
        }
    }
    
}


int main(){
    int s;
    cin >> s;
    TreeNode<int>*root = takeInputLevelWise();
    printLevelWise(root);
}
