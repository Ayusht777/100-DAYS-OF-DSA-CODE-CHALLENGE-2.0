#include <bits/stdc++.h>
using namespace std;
// 1143. Longest Common Subsequence (Memorization)
// https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    int solveMem(string &a, string &b,int i,int j,vector<vector<int>> &dp)
    {
        //base case
        if(i == a.length()){
          return 0;
        }
        if(j == b.length()){
          return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = 0;
        if(a[i] == b[j]){
            return 1 + solveMem(a,b,i+1,j+1,dp);
        } 
        else{
            ans  = max(solveMem(a,b,i+1,j,dp),solveMem(a,b,i,j+1,dp));
        }
        return dp[i][j]=ans;
        

    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(),vector<int> (text2.length(),-1));
        return solveMem(text1,text2,0,0,dp);
    }
};