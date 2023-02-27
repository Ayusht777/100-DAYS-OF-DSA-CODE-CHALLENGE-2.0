#include <bits/stdc++.h>
using namespace std;
//44. Wildcard Matching(SO)

//https://leetcode.com/problems/wildcard-matching/
class Solution {
public:
   bool solveSO(string &str,string &pattern){
         vector<int> prev (pattern.length()+1,0);
         vector<int> curr (pattern.length()+1,0);
         prev[0] =true;
        
        for(int j=1;j<=pattern.length();j++){
            bool flag =true;
             for(int k=1 ; k<=j; k++){
                if(pattern[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }
        
        for(int i=1;i<=str.length();i++){
            for(int j=1;j<=pattern.length();j++){
                            
                    //match
                    if(str[i-1]==pattern[j-1] || pattern[j-1] == '?'){
                        curr[j]=prev[j-1];
                    }
                    else if(pattern[j-1] == '*'){
                        curr[j]= ( prev[j] || curr[j-1]);
                    }
                    else{
                         curr[j] = false;
                    }
            }
            prev  =curr;
        }

        return prev[pattern.length()];
         

       
    }
    bool isMatch(string s, string p) {
       
        return solveSO(s,p);
    }
};