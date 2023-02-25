#include <bits/stdc++.h>
using namespace std;
//375. Guess Number Higher or Lower II(Tabulation)
//https://leetcode.com/problems/guess-number-higher-or-lower-ii/

class Solution {
public:
    int solveTab(int n){
        //base case
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int start=n;start>=1;start--){
            for(int end =start;end<=n;end++){
                if(start == end){
                    continue;
                }
                else{

                 int maxi =INT_MAX;
                 for(int i =start;i<=end;i++){
                   maxi = min(maxi,i + max(dp[start][i-1],dp[i+1][end]));
                 }
                 dp[start][end] = maxi;
                }
            }

        }
        return dp[1][n];
       
    }
    int getMoneyAmount(int n) {
        
        return solveTab(n);
    }
};