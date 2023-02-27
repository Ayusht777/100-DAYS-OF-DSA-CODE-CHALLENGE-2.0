#include <bits/stdc++.h>
using namespace std;
//44. Wildcard Matching(Memorization)

//https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
   bool solveM(string &str,string &pattern,int i,int j,vector<vector<int>> &dp){
        if(i<0 && j<0){
            return true;
        }
        if(i>=0 && j<0){
            return false;
        }
        if(i<0 && j>=0){
            for(int k=0 ; k<=j; k++){
                if(pattern[k] != '*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //match
        if(str[i]==pattern[j] || pattern[j] == '?'){
              return solveM(str,pattern,i-1,j-1,dp);
        }
        else if(pattern[j] == '*'){
              return dp[i][j]=solveM(str,pattern,i-1,j,dp)|| solveM(str,pattern,i,j-1,dp);
        }
         return false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length(),vector<int> (p.length(),-1));
        return solveM(s,p,s.length()-1,p.length()-1,dp);
    }
};