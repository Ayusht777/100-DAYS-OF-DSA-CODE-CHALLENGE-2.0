#include <bits/stdc++.h>
using namespace std;
//Largest square formed in a matrix (Recursion + TAB )
// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1
class Solution{
public:
    int solveTab(vector<vector<int>> &mat,int &maxi){
        
        int r = mat.size();
        int c = mat[0].size();
        
        vector<vector<int>> dp(r+1,vector<int> (c+1,0));
        for(int i= r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                int right = dp[i][j+1];
                int diagnol = dp[i+1][j+1];
                int down = dp[i+1][j];
        
                if(mat[i][j] == 1 ){
                   dp[i][j] = 1 + min(right,min(diagnol,down));
                   maxi = max(maxi,dp[i][j]);
           
        }
        else{
              dp[i][j]= 0;
            }
            
                
        }
        }
        return 0;
        
        
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        
        int maxi=0;
        solveTab(mat,maxi);
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