#include <bits/stdc++.h>
using namespace std;
//188. Best Time to Buy and Sell Stock IV(METHOD 2)
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

class Solution {
public:
    int solve(int index,int operationNo,int  k,vector<int>& prices){
        //base case
        if(index == prices.size()){
            return 0;
        }
        if(operationNo == 2 * k){
            return 0;
        }
        int profit =0;
        if(operationNo % 2 == 0){
            int buyit =  -prices[index]  + solve(index+1,operationNo+1,k,prices);
            int buynot = 0 + solve(index+1,operationNo,k,prices);
            profit  = max(buyit,buynot); 
        }
        else{
            int sellit =  prices[index]  + solve(index+1,operationNo+1,k,prices);
            int sellnot = 0 + solve(index+1,operationNo,k,prices);
            profit  = max(sellit,sellnot); 

        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        return solve(0,0,k,prices);
    }
};