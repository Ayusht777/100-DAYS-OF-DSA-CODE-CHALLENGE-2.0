#include <bits/stdc++.h>
using namespace std;
//746. Min Cost Climbing Stairs Using DP(Space Optimization)
//https://leetcode.com/problems/min-cost-climbing-stairs/
class Solution {
public:
    int solve(vector<int> &cost,int n){
      //step 1:
      int prev2 = cost[0];
      int prev1 = cost[1];
      //step 2 loop
      for(int i=2;i<n;i++){
          int curr = cost[i] + min(prev1,prev2);
          prev2 = prev1;
          prev1 =curr; 
      }
       return min(prev1,prev2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
      int n = cost.size();
      
      return solve(cost,n);  
    }
};