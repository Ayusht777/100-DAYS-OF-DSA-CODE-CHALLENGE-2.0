#include <iostream>


using namespace std;
//Construct Tree from Inorder & Preorder
//https://practice.geeksforgeeks.org/problems/construct-tree-1/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

struct Node
{
  int data;
  Node* left;
  Node* right;
};

class Solution{
    public:
    void createmap(int in[],map<int,int> &nodeToIndex,int n){
        for(int i=0;i<n;i++){
            nodeToIndex [in[i]] =i;
        }
    }
    Node * solve(int in[],int pre[],int &index ,int inorderStart,int inorderEnd,int n,map<int,int> &nodeToIndex){
        //base case
        if(index>=n || inorderStart > inorderEnd){
            return NULL;
        }
        int element = pre[index++];
        Node * root = new Node (element);
        int posititon = nodeToIndex[element];
        
        root->left = solve(in,pre,index,inorderStart,posititon-1,n,nodeToIndex);
         root->right = solve(in,pre,index,posititon+1,inorderEnd,n,nodeToIndex);
        
        return root;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int  preOrderIndex =0;
        map<int,int> nodeToIndex;
        createmap(in,nodeToIndex,n);
        Node * ans = solve(in,pre,preOrderIndex,0,n-1,n,nodeToIndex);
        return ans;
    }
};