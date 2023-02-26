#include <bits/stdc++.h>
using namespace std;
//122. Best Time to Buy and Sell Stock II
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution {
public:
    int solve(int index,int buy,vector<int> &prices)
    {
        if(index == prices.size()){
            return 0;
        }
        int profit =0;
        if(buy){
            int buyit =  -prices[index]  + solve(index+1,0,prices);
            int buynot = 0 + solve(index+1,1,prices);
            profit  = max(buyit,buynot); 
        }
        else{
            int sellit =  prices[index]  + solve(index+1,1,prices);
            int sellnot = 0 + solve(index+1,0,prices);
            profit  = max(sellit,sellnot); 

        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return solve(0,1,prices);
    }
};