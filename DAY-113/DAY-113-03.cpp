#include <bits/stdc++.h> 
using namespace std;
//Rat in a Maze Problem - I
//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1




class Solution{
    private:
    bool issafe(int x,int y,int n,vector<vector<int>> visted,vector<vector<int>> &m){
        if((x>=0&&x<n )&&(y>=0&&y<n)&&(visted[x][y]==0&&m[x][y]==1)){
            return true;
        }
        else{
            return false;
        }
        
    }
    
    void solve(vector<vector<int>> &m, int n,vector <string> &ans,int x,int y,vector<vector<int>> visted,string path) {
        
        //you have reach xy==1
        //base case
        if(x==n-1&&y==n-1){
            ans.push_back(path);
            return;
        }
        
        visted[x][y]=1;
        
        //4 choices / dierctions
        
        // d l r u
        // down
        int newx= x+1;
        int newy= y;
        if(issafe(newx,newy,n,visted,m)){
            path.push_back('D');
             solve(m,n,ans,newx,newy,visted,path);
             path.pop_back();
             //back tracking
             
        
            
        }
        
        //left
        
        newx= x;
        newy= y-1;
        if(issafe(newx,newy,n,visted,m)){
            path.push_back('L');
             solve(m,n,ans,newx,newy,visted,path);
             path.pop_back();
             //back tracking
             
        
            
        }
        
        
            //right
        
        newx= x;
        newy= y+1;
        if(issafe(newx,newy,n,visted,m)){
            path.push_back('R');
             solve(m,n,ans,newx,newy,visted,path);
             path.pop_back();
             //back tracking
             
        
            
        }
        
        
           
            //up
        
        newx= x-1;
        newy= y;
        if(issafe(newx,newy,n,visted,m)){
            path.push_back('U');
             solve(m,n,ans,newx,newy,visted,path);
             path.pop_back();
             //back tracking
             
        
            
        }
        
        visted[x][y] =0;
        
        
        
        
    }
        
   
    public:
    vector<string> findPath(vector<vector<int>> &m, int n){
        // Your code goes here
        
        vector <string> ans;
        //agar first position 0 hojya toh
        if(m[0][0]==0){
            return ans;
            
        }
        int srcx=0;
        int srcy=0;
        vector<vector<int>> visted = m;
        //n size hai
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visted[i][j]=0;
                // matlab sri value false
            }
        }
        
        string path ="";
        
        solve(m,n,ans,srcx,srcy,visted,path);
        
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};
