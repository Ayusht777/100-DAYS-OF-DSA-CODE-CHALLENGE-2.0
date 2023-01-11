#include <bits/stdc++.h>
using namespace std;
//  Cut Into Segments (DP : Tabulation )
// Maximize The Cut Segments
// https://www.codingninjas.com/codestudio/problems/cut-into-segments_1214651?leftPanelTab=0
int solveDPTab(int n, int x, int y, int z){
    vector<int> dp(n+1,INT_MIN);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        if(i-x >= 0){
            dp[i] = max(dp[i],dp[i-x] + 1);
            }
        if(i-y >= 0){
            dp[i] = max(dp[i],dp[i-y] + 1);
        }
        if(i-z >= 0){
            dp[i] = max(dp[i],dp[i-z] + 1);
        }
    }
     if(dp[n] < 0)
    {
        return 0;
    }
     
    return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	//STEP 1 :
    vector<int> dp(n+1,-1);
    int ans = solveDPTab(n,x,y,z);
    if(ans < 0){
        return 0;
        //no possible solution
    }
    return ans;
}