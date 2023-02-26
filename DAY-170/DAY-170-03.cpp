#include <bits/stdc++.h>
using namespace std;
//122. Best Time to Buy and Sell Stock II (Memorization)
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution {
public:
    int solveMem(int index,int buy,vector<int> &prices, vector<vector<int>> &dp)
    {
        if(index == prices.size()){
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
        int profit =0;
        if(buy){
            int buyit =  -prices[index]  + solveMem(index+1,0,prices,dp);
            int buynot = 0 + solveMem(index+1,1,prices,dp);
            profit  = max(buyit,buynot); 
        }
        else{
            int sellit =  prices[index]  + solveMem(index+1,1,prices,dp);
            int sellnot = 0 + solveMem(index+1,0,prices,dp);
            profit  = max(sellit,sellnot); 

        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solveMem(0,1,prices,dp);
    }
};