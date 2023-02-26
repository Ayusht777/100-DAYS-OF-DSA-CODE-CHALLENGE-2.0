#include <bits/stdc++.h>
using namespace std;
//188. Best Time to Buy and Sell Stock IV(METHOD 2 - Memorization)
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
class Solution {
public:
    int solveMem(int index,int operationNo,int  k,vector<int>& prices,vector<vector<int>> &dp){
        //base case
        if(index == prices.size()){
            return 0;
        }
        if(operationNo == 2 * k){
            return 0;
        }
        if(dp[index][operationNo]!=-1){
            return dp[index][operationNo];
        }
        int profit =0;
        if(operationNo % 2 == 0){
            int buyit =  -prices[index]  + solveMem(index+1,operationNo+1,k,prices,dp);
            int buynot = 0 + solveMem(index+1,operationNo,k,prices,dp);
            profit  = max(buyit,buynot); 
        }
        else{
            int sellit =  prices[index]  + solveMem(index+1,operationNo+1,k,prices,dp);
            int sellnot = 0 + solveMem(index+1,operationNo,k,prices,dp);
            profit  = max(sellit,sellnot); 

        }
        return dp[index][operationNo] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int> (2*k,-1));
        return solveMem(0,0,k,prices,dp);
    }
};