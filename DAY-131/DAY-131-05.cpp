#include <iostream>
#include <queue>
#include <stack>

using namespace std;

//Check for Balanced Tree
// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
//this approcha time compilxet o(n^2)
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
    int height(struct Node* node){
        //base case
        if(node ==NULL){
            return 0;
        }
        
        int left = height(node->left);
        int right = height(node->right);
        
        int ans = max(left,right) +1;
        
        return ans;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        // base case
        if(root ==NULL){
            return true;
        }
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        bool diff = abs(height(root->left)-height(root->right)) <=1;
        
        if(left && right && diff == true){
            return true;
            
        }
        else{
            return false;
        }
        
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