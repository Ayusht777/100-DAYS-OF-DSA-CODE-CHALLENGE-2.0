#include <bits/stdc++.h>
using namespace std;
//Is Binary Tree Heap
//https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1

class Solution {
  public:
    int countNode(struct Node* root){
        //base case
        if(root ==NULL){
            return  0;
        }
        
        int ans = 1 + countNode(root->left) + countNode(root->right);
        return ans;
        
    }
    bool isCBT(struct Node* root,int index,int cnt){
        //base case
        if(root==NULL){
            return true;
        }
        if(index >= cnt){
            return false;
        }
        else{
            bool left = isCBT(root->left,2*index + 1,cnt);
            bool right = isCBT(root->right,2*index + 2,cnt);
            return (left && right);
        }
        
        
    }
    bool isMaxOrder(struct Node* root){
        //leaf Node
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        
        if(root->right == NULL){
            return (root->data > root->left->data);
        }
        
        else{
            bool left =isMaxOrder(root->left);
            bool right =isMaxOrder(root->right);
            return (left  && right && (root->data > root->left->data && root->data > root->right->data) );
        }
        
        
    }
    bool isHeap(struct Node* tree) {
        int index =0;
        int totalCount = countNode(tree);
        if(isCBT(tree,index,totalCount) && isMaxOrder(tree))
        {
            return true;
        }
        else{
            return false;
        }
    }
};