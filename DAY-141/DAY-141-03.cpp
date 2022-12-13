#include <bits/stdc++.h>
using namespace std;
// Largest BST 
// https://www.codingninjas.com/codestudio/problems/largest-bst_2098944?leftPanelTab=0 
template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };


class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};
info solve(TreeNode<int> *root,int &ans){
   //base case
    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0};
    }
    info left = solve(root->left,ans);
    info right =solve(root->right,ans);
    info curr;
    curr.size =left.size+ right.size + 1;
    curr.maxi = max(root->data,right.maxi);
    curr.mini = min(root->data,left.mini);
    
    if(left.isBST && right.isBST &&(root->data > left.maxi && root->data < right.mini)){
        curr.isBST =true;
    }
    else{
     curr.isBST = false;
    }
    //answer ko update
    if(curr.isBST){
        ans  = max(ans,curr.size);
        
    }
    return curr;
    
    
}
int largestBST(TreeNode<int>* root) 
{
    int maxSize =0;
    info temp =solve(root,maxSize);
    return maxSize;
    
}