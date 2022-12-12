#include <bits/stdc++.h>
using namespace std;
//Check for BST
// Validate BST 
//https://practice.geeksforgeeks.org/problems/check-for-bst/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool checkBST(Node * root,int min , int max){
        if(root==NULL){
            return true;
        }
        
        if(root->data > min && root->data < max){
            bool left =checkBST(root->left,min,root->data);
            bool right =checkBST(root->right,root->data,max);
            return left && right;
        }
        else{
            return false;
        }
    }
    bool isBST(Node* root) 
    {
       return checkBST(root,INT_MIN,INT_MAX);
    }
};