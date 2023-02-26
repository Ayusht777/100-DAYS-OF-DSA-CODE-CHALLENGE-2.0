#include <bits/stdc++.h>
using namespace std;
// 123. Best Time to Buy and Sell Stock III(Tabulation)
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

class Solution {
public:
    int solveTab(vector<int> &prices)
    {
       int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(3,0)));
        for(int index =n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                for(int limit =1;limit<=2;limit++){
                        int profit =0;
                        if(buy){
                            int buyit =  -prices[index]  + dp[index+1][0][limit];
                            int buynot = 0 + dp[index+1][1][limit];
                            profit  = max(buyit,buynot); 
                        }
                        else{
                            int sellit =  prices[index]  + dp[index+1][1][limit-1];
                            int sellnot = 0 + dp[index+1][0][limit];
                            profit  = max(sellit,sellnot); 

                        }
                        dp[index][buy][limit] = profit;
                            
                    }
            }
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& prices) {
        
        return solveTab(prices);
    }
};