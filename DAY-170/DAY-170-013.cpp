#include <bits/stdc++.h>
using namespace std;
//188. Best Time to Buy and Sell Stock IV(METHOD 2 - Tabulation)
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

class Solution {
public:
    int solveTab(int  k,vector<int>& prices){
         int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2*k+1,0));
        for(int index =n-1;index>=0;index--){
            for(int operationNo = 0;operationNo<2*k;operationNo++){
                 int profit =0;
                    if(operationNo % 2 == 0){
                        int buyit =  -prices[index]  + dp[index+1][operationNo+1];
                        int buynot = 0 + dp[index+1][operationNo];
                        profit  = max(buyit,buynot); 
                    }
                    else{
                        int sellit =  prices[index]  + dp[index+1][operationNo+1];
                        int sellnot = 0 + dp[index+1][operationNo];
                        profit  = max(sellit,sellnot); 

                    }
                    dp[index][operationNo] = profit;
                    }
        }
        return dp[0][0];
    }
    int maxProfit(int k, vector<int>& prices) {
       
        return solveTab(k,prices);
    }
};
