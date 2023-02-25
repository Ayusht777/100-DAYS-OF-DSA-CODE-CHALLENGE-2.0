#include <bits/stdc++.h>
using namespace std;
//375. Guess Number Higher or Lower II(Memorization)
//https://leetcode.com/problems/guess-number-higher-or-lower-ii/

class Solution {
public:
    int solveMem(int start,int end,vector<vector<int>> &dp){
        //base case
        if(start>=end){
            return 0;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        int maxi =INT_MAX;
        for(int i =start;i<=end;i++){
            maxi = min(maxi,i + max(solveMem(start,i-1,dp),solveMem(i+1,end,dp)));
        }
        return dp[start][end] = maxi;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solveMem(1,n,dp);
    }
};