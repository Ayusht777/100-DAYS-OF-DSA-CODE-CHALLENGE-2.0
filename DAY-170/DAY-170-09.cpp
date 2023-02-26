#include <bits/stdc++.h>
using namespace std;
// 123. Best Time to Buy and Sell Stock III(Space Optimization)
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

class Solution {
public:
    int solveSO(vector<int> &prices)
    {
       int n = prices.size();
        vector<vector<int>> curr(2,vector<int>(3,0));
        vector<vector<int>> next(2,vector<int>(3,0));
        for(int index =n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                for(int limit =1;limit<=2;limit++){
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
        return next[1][2];
    }
    int maxProfit(vector<int>& prices) {
        
        return solveSO(prices);
    }
};