#include <bits/stdc++.h>
using namespace std;
//Kth largest element in BST
//https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution
{   
    public:
    int solve(Node* root,int &i, int k){
    //base case
    if(root ==NULL ){
        return -1;
    }
    int right = solve(root->right,i,k);
    if(right!=-1){
        return right;
    }
    i++;
    if(k==i){
        return root->data;
    }
    // r
    return solve(root->left,i,k);
}
    int kthLargest(Node *root, int K)
    {
         int i =0;
         
         int ans = solve(root,i,K);
    }
};