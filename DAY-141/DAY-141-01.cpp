#include <bits/stdc++.h>
using namespace std;
// Merge Two BSTs 
//https://www.codingninjas.com/codestudio/problems/h_920474?leftPanelTab=0

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };



void inorder(TreeNode<int> *root,vector<int> &v){
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
    
}
vector<int> merge2Bst(vector<int> &v1 ,vector<int> &v2){
   vector<int> m(v1.size()+v2.size());
   int i=0,j=0,k=0;
    
   //traverse karo;
    while(i<v1.size() && j<v2.size()){
        if(v1[i]<v2[j]){
            m[k++] = v1[i];
            i++;
        }
        else{
            m[k++] = v2[j];
            j++;
        }
    }
    //if one length is etxra
    while(i<v1.size()){
          m[k++] = v1[i];
          i++;
    }
    while(j<v2.size()){
          m[k++] = v2[j];
          j++;
    }
    
    return m;
    
}
TreeNode<int>* inorderBst(int s,int e,vector<int> &in){
    //b ase case
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    TreeNode<int>* temp = new TreeNode<int>(in[mid]);
    temp->left = inorderBst(s,mid-1,in);
    temp->right = inorderBst(mid+1,e,in);
    return temp;
    
    
} 
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    //Step 1 : Store Inorder
    vector <int> bst1,bst2;
    //inorder travsel in bst1
    inorder(root1,bst1);
    //inorder travsel in bst2
    inorder(root2,bst2);
    //merge 2 sorted array
    vector<int> ans = merge2Bst(bst1,bst2);
   
   
    int s =0,e= ans.size()-1;
    return inorderBst(s,e,ans);
    
    
    
    
}