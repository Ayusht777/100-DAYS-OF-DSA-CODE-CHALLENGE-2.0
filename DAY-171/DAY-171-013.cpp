#include <bits/stdc++.h>
using namespace std;
//44. Wildcard Matching(Tabulation)

//https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
   bool solveTab(string &str,string &pattern){
         vector<vector<int>> dp(str.length()+1,vector<int> (pattern.length()+1,0));
         dp[0][0] =true;
        
        for(int j=1;j<=pattern.length();j++){
            bool flag =true;
             for(int k=1 ; k<=j; k++){
                if(pattern[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        
        for(int i=1;i<=str.length();i++){
            for(int j=1;j<=pattern.length();j++){
                            
                    //match
                    if(str[i-1]==pattern[j-1] || pattern[j-1] == '?'){
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else if(pattern[j-1] == '*'){
                        dp[i][j]= ( dp[i-1][j] || dp[i][j-1]);
                    }
                    else{
                         dp[i][j] = false;
                    }
            }
        }

        return dp[str.length()][pattern.length()];
         

       
    }
    bool isMatch(string s, string p) {
       
        return solveTab(s,p);
    }
};