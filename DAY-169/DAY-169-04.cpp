#include <bits/stdc++.h>
using namespace std;
//1130. Minimum Cost Tree From Leaf Values
//https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

class Solution {
public:
    int solve(vector<int> &arr,map<pair<int,int>,int> &maxi,int left,int right){
        //leaf node
        if(left == right){
            return 0;
        }
        int ans =INT_MAX;
        for(int i = left ; i < right ; i++){
            ans =min(ans,maxi[{left,i}]*maxi[{i+1,right}] + solve(arr,maxi,left,i) + solve(arr,maxi,i+1,right));

        }
        return ans;

    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int> maxi;

        for(int i=0;i<arr.size();i++){
            maxi[{i,i}] =arr[i];
            for(int j=i+1;j<arr.size();j++){
                maxi[{i,j}] =max(arr[j],maxi[{i,j-1}]);
            }
        }
        return solve(arr,maxi,0,arr.size()-1);
    }

};