#include<bits/stdc++.h>
#include <queue>
#include <algorithm>
//Reverse Level Order Traversal 
//https://www.codingninjas.com/codestudio/problems/reverse-level-order-traversal_764339?leftPanelTab=0   
template <typename T>

    class TreeNode {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };



vector<int> reverseLevelOrder(TreeNode<int>* root) {
  if (root == NULL) {  // base ciondtion ha in chuiyo ki
    vector<int> s;
    return s;
  }
  queue<TreeNode<int>*> q;
  vector<int> s;
  q.push(root);

  while (!q.empty()) {
    TreeNode<int>* temp = q.front();
    q.pop();

    s.push_back(temp->val);
    // phele yeha right node ko acces karga

    if (temp->left) {
      q.push(temp->left);
    }
    if (temp->right) {
      q.push(temp->right);
    }
  }
  reverse(s.begin(), s.end());
  return s;
}