#include <iostream>
#include <queue>


using namespace std;
// Right View of Binary Tree
// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; s

// Should return  right view of tree
class Solution
{   
    public:
    void solve(Node *root,vector<int> &ans ,int level){
    //base case
    if(root ==NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->data);
        
    }
    solve(root->right,ans,level+1);
    solve(root->left,ans,level+1);
    
    }
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       vector <int> ans;
      solve(root,ans,0);
   
     return ans;
    }
};
