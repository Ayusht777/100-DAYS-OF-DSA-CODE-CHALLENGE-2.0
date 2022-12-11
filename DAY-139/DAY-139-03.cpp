#include <bits/stdc++.h>
using namespace std;

// Predecessor And Successor In BST  (Itreative)
//https://www.codingninjas.com/codestudio/problems/_893049?leftPanelTab=0

template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
};

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{

    pair <int,int> ans(-1,-1);
    BinaryTreeNode<int>*  temp1 = root;
    
    while(temp1!=NULL){

        if(temp1->data > key){
            //succesr
            ans.second = temp1->data;
            temp1 = temp1->left;
        }
        else{
             temp1 = temp1->right;
        }
    }
    temp1 = root;
    
      while(temp1!=NULL){
        if(temp1->data < key){
            //succesr
            ans.first = temp1->data;
            temp1 = temp1->right;
        }
        else{
             temp1 = temp1->left;
        }
      }
    
    return ans;
}

