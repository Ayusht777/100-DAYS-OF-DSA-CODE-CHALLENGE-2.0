#include <bits/stdc++.h>
using namespace std;
//1218. Longest Arithmetic Subsequence of Given Difference
//https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int ans = 0;
        for(int i = 0;i<arr.size();i++){
            int temp = arr[i] - difference;
            int tempAns = 0;
            //chekc answer exist for temp already or not
            if(dp.count(temp)){
                tempAns = dp[temp];
            }
            //currnet answer update
            dp[arr[i]] = 1 + tempAns;
            //ans update
            ans = max(ans,dp[arr[i]]);
     
        }
        return ans;
    }
    
};