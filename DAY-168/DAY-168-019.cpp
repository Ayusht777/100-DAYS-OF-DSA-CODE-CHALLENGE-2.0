#include <bits/stdc++.h>
using namespace std;
//96. Unique Binary Search Trees (Tabulation)
//https://leetcode.com/problems/unique-binary-search-trees/description/
class Solution {
public:
    int solveTab(int n){
      vector<int> dp(n+1,0);
      dp[0] = dp[1] = 1;
       for(int i=2;i<=n;i++){
           for(int j=1;j<=i;j++){
               dp[i] += dp[j-1] *dp[i-j];

           }
       }
       return dp[n];

    }
    int numTrees(int n) {
        
        return solveTab(n);
    }
};