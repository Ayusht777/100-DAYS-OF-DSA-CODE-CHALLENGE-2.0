#include <iostream>


using namespace std;
//Kth Ancestor in a Tree
//https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
struct Node
{
	int data;
	struct Node *left, *right;
};

Node * solve(Node * root,int &k,int node){
    //base case
    if(root ==NULL){
        return NULL;
    }
    if(root->data ==node){
        return root;
    }
    
    //recursion call
    
    
    Node * left =solve(root->left,k,node);
   Node * right  = solve(root->right,k,node);
    
    //wapsi agya call back
    
    if(left!=NULL && right ==NULL){
        k--;
        if(k<=0){
            //ans lock
            k = INT_MAX;
            return root;
        }
        
            return left;
        
    }
     if(left==NULL && right !=NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        
            return right;
        
    }
    
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node * ans =solve(root,k,node);
    if(ans==NULL||ans->data ==node){
        return -1;
    }
    else{
        return ans->data;
    }
}
 