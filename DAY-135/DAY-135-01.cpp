#include <iostream>


using namespace std;
//Lowest Common Ancestor in a Binary Tree
//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        //base case
        if(root == NULL){
            return NULL;
        }
        if(root->data ==n1 || root->data ==n2){
            return root;
        }
        
        Node * leftans = lca(root->left,n1,n2);
        Node * rightans = lca(root->right,n1,n2);
        
        if(leftans!=NULL && rightans!=NULL){
            return root;
            //yeahi toh ansh ahi
        }
        
        else if(leftans==NULL && rightans !=NULL){
            return rightans;
        }
         else if(leftans!=NULL && rightans ==NULL){
            return leftans;
        }
        else{
            //baki doni hai null
            return NULL;
        }
        
    }
};