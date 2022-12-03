#include <iostream>
#include <queue>
#include <stack>

using namespace std;

//100. Same Tree

// Check Identical Trees 
//https://leetcode.com/problems/same-tree/description/


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 
 class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //base case
        if(p ==NULL || q == NULL){
            return p==q;//balanced hai
        }
        
        if((p ==NULL && q!=NULL) ||(p !=NULL && q ==NULL)  ){
            return false;
        }
        
        bool left =isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);
        
        bool value = (p->val  == q->val); // agar shai hai to iska true ste kardo
        
        if(left&&right&&value){
            return true;
        }
        else{
            return false;
        }
    }
};
