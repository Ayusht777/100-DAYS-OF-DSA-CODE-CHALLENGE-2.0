#include <bits/stdc++.h>
using namespace std;
//  Merge K Sorted Arrays 
// https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0

class node{
    public:
    int data;
    int i;
    int j;
    //constuctor
    node(int data,int row ,int col){
        this->data =data;
        i = row;
        j = col;
        
    }
};
class compare{
    public:
    bool operator()(node * a, node * b){
        return ( a -> data > b -> data);
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node * ,vector <node *>,compare > q;
    
    //step 1 : Sara Arrays  K  first element Insert at H
    for(int i=0; i < k; i++){
        node * temp =new node(kArrays[i][0] ,i,0);
        q.push(temp);
    }
    
    vector<int> ans;
    
    //step 2 :
    
    while(q.size() > 0){
        node * temp = q.top();
        
        ans.push_back(temp -> data);
        q.pop();
        
        int i = temp -> i;
        int j = temp -> j;
        
        if(j+1 < kArrays[i].size()){
            node * next  = new node(kArrays[i][j+1] , i , j+1);
            q.push(next);
        }
    }
    return ans;
    
}
