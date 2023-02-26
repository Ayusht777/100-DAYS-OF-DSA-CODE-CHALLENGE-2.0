#include <bits/stdc++.h>
using namespace std;
// 123. Best Time to Buy and Sell Stock III(Memorization)
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

class Solution {
public:
    int solveMem(int index,int buy,vector<int> &prices,int limit,vector<vector<vector<int>>> &dp )
    {
        if(index == prices.size()){
            return 0;
        }
        if(limit == 0){
            return  0;
        }
        if(dp[index][buy][limit] != -1){
            return dp[index][buy][limit];
        }
        int profit =0;
        if(buy){
            int buyit =  -prices[index]  + solveMem(index+1,0,prices,limit,dp);
            int buynot = 0 + solveMem(index+1,1,prices,limit,dp);
            profit  = max(buyit,buynot); 
        }
        else{
            int sellit =  prices[index]  + solveMem(index+1,1,prices,limit-1,dp);
            int sellnot = 0 + solveMem(index+1,0,prices,limit,dp);
            profit  = max(sellit,sellnot); 

        }
        return dp[index][buy][limit] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(3,-1)));
        return solveMem(0,1,prices,2,dp);
    }
};