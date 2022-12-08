#include <iostream>


using namespace std;
//Construct Tree from Inorder & Preorder
//https://practice.geeksforgeeks.org/problems/construct-tree-1/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//extra trevase kar hai findposition pa
struct Node
{
  int data;
  Node* left;
  Node* right;
};

class Solution{
    public:
    int findPosititon(int in[],int element,int n){
        for(int i=0;i<n;i++){
            if(in[i]==element){
                return i;
            }
        }
        return -1;
    }
    Node * solve(int in[],int pre[],int &index ,int inorderStart,int inorderEnd,int n){
        //base case
        if(index>=n || inorderStart > inorderEnd){
            return NULL;
        }
        int element = pre[index++];
        Node * root = new Node (element);
        int posititon = findPosititon(in,element,n);
        
        root->left = solve(in,pre,index,inorderStart,posititon-1,n);
         root->right = solve(in,pre,index,posititon+1,inorderEnd,n);
        
        return root;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int  preOrderIndex =0;
        Node * ans = solve(in,pre,preOrderIndex,0,n-1,n);
        return ans;
    }
};