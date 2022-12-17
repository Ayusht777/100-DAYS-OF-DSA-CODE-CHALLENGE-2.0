#include <bits/stdc++.h>
using namespace std;
// Smallest Range From K Sorted List 
// https://www.codingninjas.com/codestudio/problems/smallest-range-from-k-sorted-list_1069356?leftPanelTab=0

class node{
      public:
      int data;
      int row;
      int col;
      //constructor
      node(int data,int row,int col){
          this->data = data;
          this->row = row;
          this->col = col;
      }
};
class compare{
    public:
    bool operator()(node * a,node * b){
        return a -> data > b -> data;
    } 
};
int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini =INT_MAX ,maxi = INT_MIN;
    // min heap
    priority_queue<node *,vector<node *> ,compare > q;
    
    //step 1 :create a min heap for starting element of each list and tracking mini/maxi value
    for(int i = 0;i < k; i++){
        int element = a[i][0];
        mini = min(mini,element);
        maxi = max(maxi,element);
        q.push(new node(element ,i ,0));
    }
    
    int start = mini , end  = maxi;
    
    //process range
    
    while(!q.empty()){
       //mini fetch 
        node * temp = q.top();
        q.pop();
        
        mini = temp->data;
        
        //range or answer updation
        if(maxi  - mini < end - start){
            start = mini;
            end  = maxi;
        }
        //next elements exists
        if(temp -> col + 1 < n){
            maxi = max(maxi,a[temp -> row][temp -> col + 1]);
            q.push(new node(a[temp -> row][temp -> col + 1],temp -> row ,temp -> col + 1));
            
        }
        else{
            // next  element exists 
            break;
        }
        
    }
    // returning the difference of range
    return (end - start + 1);
    
}