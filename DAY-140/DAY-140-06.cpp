#include <bits/stdc++.h>
using namespace std;
// Pair Sum in BST.
//Find a pair with given target in BST 
//https://www.codingninjas.com/codestudio/problems/pair-sum-in-bst_920493?leftPanelTab=0

template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };


void inorder(BinaryTreeNode<int> *root,vector <int> &v){
    if(root == NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
    
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector <int> inorderVal;
    inorder(root,inorderVal);
    //2pointer approach i and j
    
    int i = 0;
    int j = inorderVal.size()-1;
    
    while(i<j){
        int sum = inorderVal[i] + inorderVal[j];
        if(sum==k){
            return true;
        }
       else if(sum > k){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
    
}