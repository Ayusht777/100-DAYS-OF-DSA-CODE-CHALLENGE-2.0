#include <bits/stdc++.h>

using namespace std;

//Kth smallest element
//https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
       priority_queue<int> q;
       
       //step 1 : sraha k element max heap ma dalo
       for(int i=0;i<k;i++){
           q.push(arr[i]);
       }
       //step 2 : remaing k elemnet ma sa smallest elemnent q ma dalo
       for(int i=k; i<=r ;i++){
           if(arr[i]<q.top()){
               q.pop();
               q.push(arr[i]);
           }
       }
       
       //step 3 : ans at top
       
       int ans = q.top();
       
       return ans;
    }
};
