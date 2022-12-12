#include <bits/stdc++.h>
using namespace std;
// Find K-th smallest Element in BST 
//https://www.codingninjas.com/codestudio/problems/find-k-th-smallest-element-in-bst_1069333?leftPanelTab=0



    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

int solve(BinaryTreeNode<int>* root,int &i, int k){
    //base case
    if(root ==NULL){
        return -1;
    }
    int left = solve(root->left,i,k);
    if(left!=-1){
        return left;
    }
    i++;
    if(k==i){
        return root->data;
    }
    // r
    return solve(root->right,i,k);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i =0;
    int ans = solve(root,i,k);
    
}