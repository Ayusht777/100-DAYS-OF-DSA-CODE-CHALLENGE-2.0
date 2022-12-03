#include <iostream>
#include <queue>
#include <stack>

using namespace std;
//Count Leaf Nodes 
//https://www.codingninjas.com/codestudio/problems/count-leaf-nodes_893055?leftPanelTab=0

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    


void inorder(BinaryTreeNode<int> *root ,int &count){
  //LNR
  // base case
  if(root==NULL){
    return;
  }

  inorder(root->left,count);
 if(root->left == NULL && root->right ==NULL){
     count++;
 }
  inorder(root->right,count);


}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    int count=0;
    inorder(root,count);
    return count;
}



int main(){

}
