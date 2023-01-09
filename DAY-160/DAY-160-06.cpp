#include <bits/stdc++.h>
using namespace std;
//746. Min Cost Climbing Stairs Using DP
//https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int solve(vector<int> &cost,int n,vector<int> &dp){
        //base case
        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return cost[1];
        }
        //step 2 :
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = cost[n] + min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return dp[n];

    }
    int minCostClimbingStairs(vector<int>& cost) {
      int n = cost.size();
      //step 1 :
      vector<int> dp(n+1,-1);
      int ans = min(solve(cost,n-1,dp),solve(cost,n-2,dp));
      return ans;  
    }
};
