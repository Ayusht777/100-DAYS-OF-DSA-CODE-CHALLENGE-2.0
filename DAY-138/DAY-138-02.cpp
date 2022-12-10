#include <bits/stdc++.h>
using namespace std;
// Search In BST
//700. Search in a Binary Search Tree
 
//https://www.codingninjas.com/codestudio/problems/search-in-bst_1402878?leftPanelTab=0

class BinaryTreeNode {
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

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    //base case
    if(root ==NULL){
        return false;
    }
    if(root->data ==x){
        return true;
    }
    
    if(root->data > x){
        //left part ma jao
        return searchInBST(root->left,x);
    }
    else{
        //right part ma jao
        return searchInBST(root->right,x);
    }
}
