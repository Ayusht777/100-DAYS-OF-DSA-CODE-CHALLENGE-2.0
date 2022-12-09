#include <bits/stdc++.h>
using namespace std;
//Morris traversal for Inorder
//https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
/*****************************************************************************************
 * algo 
 * 1. Initialize current as root 
 * 2. While current is not NULL
   If the current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Find rightmost node in current left subtree OR
              node whose right child == current.
         If we found right child == current
             a) Update the right child as NULL of that node whose right child is current
             b) Print current’s data
             c) Go to the right, i.e. current = current->right
         Else
             a) Make current as the right child of that rightmost 
                node we found; and 
             b) Go to this left child, i.e., current = current->left
*/


class node{
      public :
        int data;
        node *left;
        node *right;

        node(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };

void MorrisTraversal(node * root){

    if(root ==NULL){
        return ;
    }

    node * curr =NULL;
    node  * pre =NULL;
//current as root 
    curr = root;

    while(curr!=NULL){
      if(curr->left ==NULL){
        cout<<curr->data<<" ";
        curr = curr->right;
      }
      else{
         pre = curr->left;

         while(pre->right !=NULL && pre->right !=curr ){
            pre = pre->right;

         }

         if(pre->right ==NULL){
            pre->right = curr;
            curr = curr->left;
         }

         else{
            pre->right = NULL;
            cout << curr->data << " ";
            curr = curr->right;
         }
      }

    }

   

}
node *nnode(int data)
{
    node *n = new node(data);
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return (n);
}
int main(){
    node * x = nnode(1);
    x->left = nnode(2);
     x->right =nnode(3);
     x->left->left = nnode(4);
    x->left->right = nnode(5);

    MorrisTraversal(x);
    
}
