#include <bits/stdc++.h>
using namespace std;
//188. Best Time to Buy and Sell Stock IV
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
class Solution {
public:
   int solveSO(vector<int> &prices,int k)
    {
       int n = prices.size();
        vector<vector<int>> curr(2,vector<int>(k+1,0));
        vector<vector<int>> next(2,vector<int>(k+1,0));
        for(int index =n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                for(int limit =1;limit<=k;limit++){
                        int profit =0;
                        if(buy){
                            int buyit =  -prices[index]  + next[0][limit];
                            int buynot = 0 + next[1][limit];
                            profit  = max(buyit,buynot); 
                        }
                        else{
                            int sellit =  prices[index]  + next[1][limit-1];
                            int sellnot = 0 + next[0][limit];
                            profit  = max(sellit,sellnot); 

                        }
                        curr[buy][limit] = profit;
                            
                    }
                    next =curr;
            }
        }
        return next[1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        return solveSO(prices,k);
    }
};