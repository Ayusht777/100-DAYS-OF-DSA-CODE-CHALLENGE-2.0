#include <bits/stdc++.h>
using namespace std;
//96. Unique Binary Search Trees (Memorization)
//https://leetcode.com/problems/unique-binary-search-trees/description/

class Solution {
public:
    int solveMem(int n,vector<int> &dp){
      if(n<=1){
          return 1;  
        }
       if(dp[n]!=-1){
           return dp[n];
       }
        int ans = 0;
        //think i as root node
        for(int i=1;i<=n;i++){
            ans +=solveMem(i-1,dp)*solveMem(n-i,dp);
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return solveMem(n,dp);
    }
};