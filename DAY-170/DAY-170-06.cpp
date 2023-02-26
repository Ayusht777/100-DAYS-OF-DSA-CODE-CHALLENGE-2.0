#include <bits/stdc++.h>
using namespace std;
// 123. Best Time to Buy and Sell Stock III
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

class Solution {
public:
    int solve(int index,int buy,vector<int> &prices,int limit )
    {
        if(index == prices.size()){
            return 0;
        }
        if(limit == 0){
            return  0;
        }
        int profit =0;
        if(buy){
            int buyit =  -prices[index]  + solve(index+1,0,prices,limit);
            int buynot = 0 + solve(index+1,1,prices,limit);
            profit  = max(buyit,buynot); 
        }
        else{
            int sellit =  prices[index]  + solve(index+1,1,prices,limit-1);
            int sellnot = 0 + solve(index+1,0,prices,limit);
            profit  = max(sellit,sellnot); 

        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return solve(0,1,prices,2);
    }
};