#include <iostream>
#include <queue>
#include <stack>

using namespace std;

//Check for Balanced Tree
// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
//this approcha time compilxet o(n)
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


class Solution{
    public:
    pair<bool,int> isBalancedFast(Node *root){
        //base case
        if(root ==NULL){ 
            pair<bool,int> p =make_pair(true,0); //height and  bool function
            return p;
            
        }
        
        pair<int,int> left = isBalancedFast(root->left); //ki root ka left part chek karo 
        
        pair<int,int> right = isBalancedFast(root->right); //ki root ka right part chek karo 
        
        bool leftAns = left.first;
        bool rightAns = right.first;  //fist block ma chek karge true ya false
        
        bool diff =abs(left.second- right.second) <=1 ; 
        //check height of both opart
        
        pair<bool,int> ans;
        ans.second = max(left.second,right.second) + 1 ; //find the height
        
        if(leftAns && rightAns && diff){
            ans.first = true;       
            
        }
        
        else{
            ans.first =false;
        }
        
        return ans;
        
    }
        
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
};

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isBalanced(root) << endl;
    }
    return 0;
}