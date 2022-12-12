#include <bits/stdc++.h>
using namespace std;
// Flatten BST To A Sorted List 
//https://www.codingninjas.com/codestudio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0
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


void inorder(TreeNode<int> *root,vector <int> &v){
    if(root == NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
    
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
     vector <int> inorderVal;
    inorder(root,inorderVal);
    
    int n = inorderVal.size();
    
    TreeNode<int>* newroot  = new TreeNode<int>(inorderVal[0]);
    TreeNode<int>* curr = newroot;
    //2nd step
    for(int i = 1 ;i<n;i++){
        TreeNode<int>* temp = new TreeNode<int>(inorderVal[i]);
        curr->left =NULL;
        curr->right = temp;
        curr =temp;
        
        
    }
    //3rd step
    curr->left =NULL;
    curr->right =NULL;
    return newroot;
    
}
