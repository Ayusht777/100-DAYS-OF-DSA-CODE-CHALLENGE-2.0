#include <bits/stdc++.h>
using namespace std;
//746. Min Cost Climbing Stairs Using DP(Tabulation)
//https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int solve(vector<int> &cost,int n){
       //step 1 :
      vector<int> dp(n+1);
      //step2:
      dp[0] = cost[0];
      dp[1] = cost[1];
      //step 3 loop
      for(int i=2;i<n;i++){
          dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
      }
       return min(dp[n-1],dp[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
      int n = cost.size();
      
      return solve(cost,n);  
    }
};