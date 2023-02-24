#include <bits/stdc++.h>
using namespace std;
//Partition Equal Subset Sum
//https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

class Solution{
public:
    bool solve(int index,int N,int arr[],int target){
        //base case
        if(index>=N){
            return 0;
        }
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
         
        bool incl = solve(index+1,N,arr,target-arr[index]);
        bool excl = solve(index+1,N,arr,target-0);
        
        return incl or excl;
    }
    int equalPartition(int N, int arr[])
    {
        int total = 0;
        //sum of all element
        for(int i=0;i<N;i++){
            total = total + arr[i];
        }
        
        if(total & 1){
            return 0;
        }
        int target = total/2;
        
        return solve(0,N,arr,target);
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