#include <bits/stdc++.h>
using namespace std;
// Convert BST to Min Heap 
// https://www.codingninjas.com/codestudio/problems/convert-bst-to-min-heap_920498?leftPanelTab=0

class BinaryTreeNode
{
    public:
        int data;
    BinaryTreeNode * left;
    BinaryTreeNode * right;

    BinaryTreeNode(int data)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};

void inorder(BinaryTreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);

}

void preOrder(BinaryTreeNode *root, vector<int> &ans, int &index)
{
   	//base case 
    if (root == NULL)
    {
        return;
    }

    root->data = ans[index++];
   	//yeha sorted value tree ma dalo 
   	// aur index ko aaga bado

   	//phir left call
    preOrder(root->left, ans, index);
   	//phir Right call
    preOrder(root->right, ans, index);
}

BinaryTreeNode* convertBST(BinaryTreeNode *root)
{
   	//Edge Case
    if (root == NULL)
    {
        return NULL;
    }

    vector<int> ans;
    inorder(root, ans);
    int index = 0;
    preOrder(root, ans, index);

    return root;
}