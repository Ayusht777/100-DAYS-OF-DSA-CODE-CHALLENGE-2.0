#include <bits/stdc++.h>
using namespace std;
//Largest square formed in a matrix (Space Optimization )
// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1
class Solution{
public:
    int solveSO(vector<vector<int>> &mat,int &maxi){
        
        int r = mat.size();
        int c = mat[0].size();
        vector<int> curr(c+1,0);
        vector<int> next(c+1,0);
        for(int i= r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                int right = curr[j+1];
                int diagnol = next[j+1];
                int down = next[j];
        
                if(mat[i][j] == 1 ){
                   curr[j] = 1 + min(right,min(diagnol,down));
                   maxi = max(maxi,curr[j]);
           
        }
        else{
              curr[j]= 0;
            }
            
                
        }
        next =curr;
        }
        return next[0];
        
        
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        
        int maxi=0;
        solveSO(mat,maxi);
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