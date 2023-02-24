#include <bits/stdc++.h>
using namespace std;
//96. Unique Binary Search Trees
//https://leetcode.com/problems/unique-binary-search-trees/description/
class Solution {
public:
    int numTrees(int n) {
        if(n<=1){
          return 1;  
        }
        int ans = 0;
        //think i as root node
        for(int i=1;i<=n;i++){
            ans +=numTrees(i-1)*numTrees(n-i);
        }
        return ans;

    }
};