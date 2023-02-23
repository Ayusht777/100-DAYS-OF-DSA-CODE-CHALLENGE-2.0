#include <bits/stdc++.h>
using namespace std;
// 1402. Reducing Dishes (Memorization)

// https://leetcode.com/problems/reducing-dishes/

class Solution {
public:
    int solveMem(vector<int>& satisfaction,int index,int time,vector<vector<int>> &dp){
        //base case
        if(index == satisfaction.size()){
            return 0;
        }
        if(dp[index][time] != -1){
            return dp[index][time];
        }
        int include = satisfaction[index]*(time+1) + solveMem(satisfaction,index+1,time+1,dp);
        int exclude = 0 + solveMem(satisfaction,index+1,time,dp);
        dp[index][time] = max(include,exclude);
        return dp[index][time]; 
         

    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp (n+1,vector<int>(n+1,-1));
        return solveMem(satisfaction,0,0,dp); 
    }
};