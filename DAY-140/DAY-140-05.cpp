#include <bits/stdc++.h>
using namespace std;
//Lowest Common Ancestor in a BST (iterative)
//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

Node* LCA(Node *root, int n1, int n2)
{
   //base case
    if(root==NULL){
        return root;
    }
    while(root!=NULL){
        if(root->data <n1 && root->data < n2){
            root= root->right;
        }
        else if(root->data >n1 && root->data >n2){
            root = root->left;
        }
        else {
            return root;
            
        }
    }
    
    
}