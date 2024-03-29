#include <bits/stdc++.h>
using namespace std;
//Partition Equal Subset Sum (TAb)
//https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

class Solution {
 public:
  bool solveTab(int N, int arr[], int total) {
    vector<vector<int>> dp(N + 1, vector<int>(total + 1, 0));

    for (int i = 0; i <= N; i++) {
      dp[i][0] = 1;
    }
    for (int index = N - 1; index >= 0; index--) {
      for (int target = 0; target <= total / 2; target++) {
        bool incl = 0;
        if (target - arr[index] >= 0) {
          incl = dp[index + 1][target - arr[index]];
        }
        bool excl = dp[index + 1][target - 0];

        dp[index][target] = incl or excl;
      }
    }

    return dp[0][total / 2];
  }
  int equalPartition(int N, int arr[]) {
    int total = 0;
    // sum of all element
    for (int i = 0; i < N; i++) {
      total = total + arr[i];
    }

    if (total & 1) {
      return 0;
    }

    return solveTab(N, arr, total);
  }
};
//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}