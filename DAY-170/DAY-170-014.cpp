#include <bits/stdc++.h>
using namespace std;
//188. Best Time to Buy and Sell Stock IV(METHOD 2 - SO)
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

class Solution {
public:
    int solveSO(int  k,vector<int>& prices){
         int n = prices.size();
        vector<int> curr (2*k+1,0);
        vector<int> next (2*k+1,0);
        for(int index =n-1;index>=0;index--){
            for(int operationNo = 0;operationNo<2*k;operationNo++){
                 int profit =0;
                    if(operationNo % 2 == 0){
                        int buyit =  -prices[index]  + next[operationNo+1];
                        int buynot = 0 + next[operationNo];
                        profit  = max(buyit,buynot); 
                    }
                    else{
                        int sellit =  prices[index]  + next[operationNo+1];
                        int sellnot = 0 + next[operationNo];
                        profit  = max(sellit,sellnot); 

                    }
                    curr[operationNo] = profit;
                    }
                    next  =curr ;
        }
        return next[0];
    }
    int maxProfit(int k, vector<int>& prices) {
       
        return solveSO(k,prices);
    }
};