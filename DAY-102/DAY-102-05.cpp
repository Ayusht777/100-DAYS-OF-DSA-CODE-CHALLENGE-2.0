
#include <bits/stdc++.h> 
//Merge Sorted Array

//https://leetcode.com/problems/merge-sorted-array/description/
//version 2


using namespace std;
void display(vector <int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";

    }
    cout<<endl;
}



    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j =n-1;
        int tar = n+m-1;
        
        while (j >=0){
            if (i>=0 && nums1[i] > nums2[j]){
                nums1[tar] = nums1[i];
                tar -=1;
                i -=1;
            }
            else{
                nums1[tar] = nums2[j];
                tar -=1;
                j -=1;
            }
        }
    }



int main(){
   vector <int> arr1 {1,2,3,0,0};
    vector <int> arr2 {4,5};
  
    display(arr1);
    display(arr2);
    merge(arr1,3,arr2,2);
    display(arr1);
   

}