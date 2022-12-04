#include <iostream>
using namespace std;
//Vertical Traversal of Binary Tree
//https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}


class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int, map<int,vector<int>>> nodes;
        queue<pair<Node*,pair<int,int>>> q;
        
        vector <int> ans;
        
        if(root == NULL){
            return ans;
        }
        
        q.push(make_pair(root,make_pair(0,0))) ;
        //////      node pas kar da  phir hroozntoal distance jo ki 0 hai aur level bhi 0  ha
        
        while(!q.empty()){
            pair<Node*,pair<int,int>> temp = q.front();
            q.pop();
            
            Node * frontNode = temp.first;
            
            int hd =temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
                
                
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
            }
            
            
        }
        //sari value kami ki vector ma dalo
        
        for(auto i :nodes){
            for(auto j :i.second){
                for(auto k : j.second){
                    ans.push_back(k);
                }
            }
        }
        
        return ans;
        
        
    }
};

int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}