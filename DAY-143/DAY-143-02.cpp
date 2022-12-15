#include <bits/stdc++.h>
using namespace std;
//Merge two binary Max heaps
//https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
class Solution{
    public:
    void heapfiy(vector<int> & arr ,int  n ,int i){
    //1 base indexing
    int largest = i; 
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < n && arr[largest] < arr[left]){
        largest =left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest] ,arr[i]);
        heapfiy(arr,n,largest);
    }
}
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        //step 1 : is to merege two vector in one
        vector<int> ans;
        for(auto i : a){
            ans.push_back(i);
        }
        for(auto i : b){
            ans.push_back(i);
        }
        //step 2 : Merge karo 2 tree ko uisng heapify
        int size = ans.size();
         for (int i = size/2 - 1; i >= 0; i--)
         {
            heapfiy(ans,size,i);

         }
         return ans;
    }
};