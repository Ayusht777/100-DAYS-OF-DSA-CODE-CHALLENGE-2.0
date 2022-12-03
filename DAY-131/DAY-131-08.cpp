#include <iostream>
#include <queue>
#include <stack>

using namespace std;
//Sum Tree
//https://practice.geeksforgeeks.org/problems/sum-tree/1

struct Node
{
    int data;
    Node* left, * right;
};

class Solution
{
    public:
    pair<bool,int> isSumTreeFast(Node *root){
        //base case
        if(root==NULL){
            pair<bool,int> p =make_pair(true,0);
            return p;
            
        }
        //leaf node
        if(root->left==NULL && root->right ==NULL){
             pair<bool,int> p =make_pair(true,root->data);
            return p;
            
        }
        
        pair<bool,int> leftAns = isSumTreeFast(root->left);
        pair<bool,int> rightAns = isSumTreeFast(root->right);
        
        bool left =leftAns.first;
        bool right =rightAns.first;
        
        bool condn = root->data == (leftAns.second + rightAns.second);
        
        pair <bool,int> ans;
        
        if(left && right && condn){
            ans.first= true;
            ans.second = 2* root->data;
            //root->data +  leftAns.second + rightAns.second;
            // 2          +  1  + 1  == 4 
            
          
        
            
        }
        
          else{
                ans.first =false;
            }
            
       return ans;
        
        
        
    }
    bool isSumTree(Node* root)
    {
        return isSumTreeFast(root).first;
    }
};


int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout <<ob.isSumTree(root) << endl;
    }
    return 1;
}