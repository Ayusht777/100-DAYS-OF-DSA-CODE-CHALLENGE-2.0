#include <bits/stdc++.h>
using namespace std;
//Largest square formed in a matrix (Recursion + Memorization )
// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1


class Solution{
public:
    int solveMem(vector<vector<int>> &mat,int i,int j,int &maxi,vector<vector<int>> &dp){
        if(i >= mat.size() || j>= mat[0].size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = solveMem(mat,i,j+1,maxi,dp);
        int diagnol = solveMem(mat,i+1,j+1,maxi,dp);
        int down = solveMem(mat,i+1,j,maxi,dp);
        
        if(mat[i][j] == 1 ){
            dp[i][j] = 1 + min(right,min(diagnol,down));
            maxi = max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j]= 0;
        }
        
        
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        vector<vector<int>> dp(n,vector<int> (m,-1));
        int maxi=0;
        solveMem(mat,0,0,maxi,dp);
        return maxi;
        
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}