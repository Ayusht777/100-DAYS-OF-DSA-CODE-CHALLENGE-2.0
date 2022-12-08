#include <iostream>


using namespace std;
//Tree from Postorder and Inorder
//https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

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

void createmap(int in[],map<int,int> &nodeToIndex,int n){
        for(int i=0;i<n;i++){
            nodeToIndex [in[i]] =i;
        }
}
   Node * solve(int in[],int post[],int &index ,int inorderStart,int inorderEnd,int n,map<int,int> &nodeToIndex){
        //base case
        if(index <0 || inorderStart > inorderEnd){
            return NULL;
        }
        int element = post[index--];
        Node * root = new Node (element);
        int posititon = nodeToIndex[element];
        root->right = solve(in,post,index,posititon+1,inorderEnd,n,nodeToIndex);
        root->left = solve(in,post,index,inorderStart,posititon-1,n,nodeToIndex);
       
        
        return root;
        
    }

//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
        int  preOrderIndex =n-1;
        map<int,int> nodeToIndex;
        createmap(in,nodeToIndex,n);
        Node * ans = solve(in,post,preOrderIndex,0,n-1,n,nodeToIndex);
        return ans;
}
