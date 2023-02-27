#include <bits/stdc++.h>
using namespace std;
//516. Longest Palindromic Subsequence
//https://leetcode.com/problems/longest-palindromic-subsequence/description/

class Solution {
public:
    int solveSO(string a, string b)
    {   int n1 = a.length();
        int n2 = b.length();
        
        vector<int> curr (n2+1,0);
        vector<int> next (n2+1,0);
        for(int i=n1-1;i>=0;i--){
            for(int j = n2-1;j>=0;j--){
                int ans = 0;
                    if(a[i] == b[j]){
                        ans =  1 + next[j+1];
                    } 
                    else{
                        ans  = max(next[j],curr[j+1]);
                    }
                    curr[j]=ans;
            }
            next  = curr;
        }
        
        return next[0];
    }
    int longestPalindromeSubseq(string s) {
        string revStr = s;
        reverse(revStr.begin(),revStr.end());
        return solveSO(s,revStr);
    }
};