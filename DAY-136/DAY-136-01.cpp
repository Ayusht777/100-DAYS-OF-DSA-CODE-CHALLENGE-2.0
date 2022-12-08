#include <iostream>


using namespace std;
//K Sum Paths
//437. Path Sum III

//https://practice.geeksforgeeks.org/problems/k-sum-paths/1
struct Node 
{
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
    void solve(Node * root,int k ,int &count,vector<int> path){
        //base case
        if(root ==NULL){
            return ;
        }
        path.push_back(root->data);
        
        //left part ma ja
        
        solve(root->left,k,count,path);
        
        //right part ma ja
        
        solve(root->right,k,count,path);
        
        //check k sum
        
        int sum=0;
        for(int i=path.size()-1;i>=0;i--){
            sum = sum + path[i];
            if(sum==k){
                count++;
            }
            
        }
        
        path.pop_back();
        //remove the value 
        
        
        
    }
    int sumK(Node *root,int k)
    {
        vector<int> path;
        int count =0;
        solve(root,k,count,path);
        return count;
    }
};


int main() {
    string tc;
    getline(cin, tc);
    int t = stoi(tc);
  
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        string key;
        getline(cin, key);
        int k=stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << "\n";
    }
    return 0;
}