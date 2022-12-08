#include <iostream>


using namespace std;
//Kth Ancestor in a Tree
//https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
struct Node
{
	int data;
	struct Node *left, *right;
};

void solve(Node* root, int node, vector<int>& v){
    
    if(root == NULL)    return;
    if(root->data == node){v.push_back(root->data); return;}
    
    if(v.empty())  solve(root->left,node,v);
    if(v.empty())  solve(root->right,node,v);

    if(!v.empty()) v.push_back(root->data);
}
int kthAncestor(Node *root, int k, int node)
{
     // Code here
    vector<int> v;
    solve(root,node,v);
    if(v.size() <= k) return -1;
    return v[k];
}
 