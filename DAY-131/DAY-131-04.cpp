#include <iostream>
#include <queue>
#include <stack>

using namespace std;

//Diameter of a Binary Tree
//https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

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

class Solution {
   
   
  public:
   //pair ek data strucrue in stl which can hold any two value of any datatype
    pair<int,int> diameterFast(Node* root){
        //base case
        
        if(root ==NULL){
            pair<int,int> p = make_pair(0,0) ; 
            //isk matlb ki height and diamter bhi 0 hai
            
            return p;
        }
        
        pair<int,int> left = diameterFast(root->left);  //function ma left Node pass kardo
        pair<int,int> right = diameterFast(root->right);  //function ma Right Node pass kardo
        
        int op1 = left.first;  //ki daimter o f left daldo
        int op2 = right.first;  //ki daimter o f right daldo
        
        int op3 = left.second + right.second +1;
        
        pair<int,int> ans;
        
        ans.first = max(op1,max(op2,op3));
        ans.second = max(left.second,right.second) +1 ; // it will store the height of the tree
        
        return ans;  //ha bajegna dono value but use firts karge
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
       return diameterFast(root).first;
       // first pa diamter store hai
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
