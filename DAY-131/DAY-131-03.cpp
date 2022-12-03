#include <iostream>
#include <queue>
#include <stack>

using namespace std;

//Diameter of a Binary Tree
//https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

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

class Solution {
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
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
         //base case
         if(root == NULL){
             return 0;
         }
         
         int op1 = diameter(root->left);
         int op2 = diameter(root->right);
         
         int op3 = height(root->left) + height(root->right) +1;
         
         int ans = max(op3 ,max(op1,op2));
         
         return ans;
    }
};

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}