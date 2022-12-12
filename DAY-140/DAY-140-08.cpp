#include <bits/stdc++.h>
using namespace std;
// Normal BST To Balanced BST 
// https://www.codingninjas.com/codestudio/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0

template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

TreeNode<int>* inorderBst(int s,int e,vector<int> &in){
    //b ase case
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    TreeNode<int>* temp = new TreeNode<int>(in[mid]);
    temp->left = inorderBst(s,mid-1,in);
    temp->right = inorderBst(mid+1,e,in);
    return temp;
    
    
} 

TreeNode<int>* balancedBst(TreeNode<int>* root) {
     vector <int> inorderVal;
    inorder(root,inorderVal);
    return (inorderBst(0,inorderVal.size()-1,inorderVal));
}


