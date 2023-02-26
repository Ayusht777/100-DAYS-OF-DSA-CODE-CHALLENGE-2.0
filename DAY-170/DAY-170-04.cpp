#include <bits/stdc++.h>
using namespace std;
//122. Best Time to Buy and Sell Stock II (Tabulation)
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution {
public:

    int solvetab(vector<int> &prices){
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int index= n-1;index>=0;index--){
            for(int buy = 0 ;buy<=1;buy++ ){
                int profit =0;
                if(buy){
                    int buyit =  -prices[index]  + dp[index+1][0];
                    int buynot = 0 + dp[index+1][1];
                    profit  = max(buyit,buynot); 
                }
                else{
                    int sellit =  prices[index]  + dp[index+1][1];
                    int sellnot = 0 + dp[index+1][0];
                    profit  = max(sellit,sellnot); 

                }
                dp[index][buy] = profit;

            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        
        return solvetab(prices);
    }
};