#include <iostream>
using namespace std;
//Boundary Traversal of binary tree
//https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
public:
    void traverseLeft(Node * root ,vector<int> &ans){
                         // root ka left and right null hai toh yeha leaf node hai
      if((root ==NULL ) || (root->left  ==NULL && root->right ==NULL )){
          return ;
      }
      ans.push_back(root->data);
      
      if(root->left !=NULL){
          traverseLeft(root->left,ans);
      }
      else{
          //right part ma jao
           traverseLeft(root->right,ans);
      }
      
      
      
    }
    void traverseLeaf(Node * root ,vector<int> &ans){
        //using LNR LOOGIC 
        //base case
        
        if(root ==NULL){
            return ;
        }
        if(root->left ==NULL &&root->right ==NULL){
            //mtlab yeh leaf node hai
              ans.push_back(root->data);
              return ;
        }
        
        //baki pehel left ma traves karo
        traverseLeaf(root->left,ans);
        //baki phir right ma traves karo
        traverseLeaf(root->right,ans);
        
        
        
    }
    
    void traverseRight(Node * root ,vector<int> &ans)
    {  // root ka left and right null hai toh yeha leaf node hai
      if((root ==NULL ) || (root->left  ==NULL && root->right ==NULL )){
          return ;
      }
     
      
      if(root->right !=NULL){
          traverseRight(root->right,ans);
      }
      else{
          //left part ma jao
           traverseRight(root->left,ans);
      }
       ans.push_back(root->data);
    } 
    vector <int> boundary(Node *root)
    {   
        vector<int> ans;
        //base case
        if(root ==NULL){
            return ans;
        }
        ans.push_back(root->data); //main node ka data store kardo
        //left part ki ma jao
        
        traverseLeft(root->left,ans);
        //traverse leaf node
        
        //leaf node left part ma hogi
        traverseLeaf(root->left,ans);
        
        //right part ma hogi
        traverseLeaf(root->right,ans);
        
        //traverse right part 
        
        traverseRight(root->right,ans);
        
        
        return ans;
        
        
    }
};

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}