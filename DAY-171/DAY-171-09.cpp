#include <bits/stdc++.h>
using namespace std;
//72. Edit Distance(SO)
//https://leetcode.com/problems/edit-distance/
class Solution {
public:
    int solveSO(string &a ,string &b){
        vector<int> curr(b.length()+1,0);
        vector<int> next(b.length()+1,0);
        
        for(int j=0;j<b.length();j++){
            next[j] = b.length()-j;
        }
        

        for(int i=a.length()-1;i>=0;i--){
            for(int j = b.length()-1;j>=0;j--){
                //catch 
                curr[b.length()] = a.length() -i;

                 int ans = 0;
                    if(a[i] == b[j]){
                        ans = next[j+1];
                    }
                    else{
                        //inseert
                        int insertAns = 1 + curr[j+1];
                        int deleteAns = 1 + next[j];
                        int replaceAns = 1  + next[j+1];
                        ans  = min(insertAns,min(deleteAns,replaceAns));
                    }
                    curr[j] = ans;
            }
            next = curr;
        }
        return next[0];

    }
    int minDistance(string word1, string word2) {
        //base case
        if(word1.length() == 0){
            return word2.length();
        }
        if(word2.length() == 0){
            return word1.length();
        }
        return solveSO(word1,word2);
    }
};