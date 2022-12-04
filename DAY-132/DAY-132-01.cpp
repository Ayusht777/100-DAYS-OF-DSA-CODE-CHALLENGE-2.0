#include <iostream>
#include <queue>
#include <stack>

using namespace std;
//ZigZag Tree Traversal
//https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector <int> result;
    	
    	if(root==NULL){
    	    return result;
    	}
    	
    	queue<Node *> q;
    	q.push(root);
    	bool leftToRight =true;
    	while(!q.empty()){
    	    int size = q.size();
    	    vector<int> ans(size);
    	    
    	    //level process 
    	    
    	    for(int i=0;i<size;i++){
    	        Node * frontNode  = q.front();
    	        q.pop();
    	        
    	        //normal insret or reverse insert
    	         int index = leftToRight ? i : size-i-1;
    	         ans[index] =frontNode->data;
    	         
    	         if(frontNode->left){
    	             q.push(frontNode->left);
    	         }
    	         if(frontNode->right){
    	             q.push(frontNode->right);
    	         }
    	    }
    	    
    	    	//direction change karna
    	leftToRight = (!leftToRight);
    	
    	for(auto x : ans){
    	    result.push_back(x);
    	}
    	    
    	}
    	
    
    	
    	return result;
    }
};


class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector <int> result;
    	
    	if(root==NULL){
    	    return result;
    	}
    	
    	queue<Node *> q;
    	q.push(root);
    	bool leftToRight =true;
    	while(!q.empty()){
    	    int size = q.size();
    	    vector<int> ans(size);
    	    
    	    //level process 
    	    
    	    for(int i=0;i<size;i++){
    	        Node * frontNode  = q.front();
    	        q.pop();
    	        
    	        //normal insret or reverse insert
    	         int index = leftToRight ? i : size-i-1;
    	         ans[index] =frontNode->data;
    	         
    	         if(frontNode->left){
    	             q.push(frontNode->left);
    	         }
    	         if(frontNode->right){
    	             q.push(frontNode->right);
    	         }
    	    }
    	    
    	    	//direction change karna
    	leftToRight = (!leftToRight);
    	
    	for(auto x : ans){
    	    result.push_back(x);
    	}
    	    
    	}
    	
    
    	
    	return result;
    }
};