
#include <bits/stdc++.h> 
//1752. Check if Array Is Sorted and Rotated
//https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/


using namespace std;
void display(vector <int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";

    }
    cout<<endl;
}


    bool check(vector<int>& nums) {

        int count =0;
        int n = nums.size();
        for(int i =1;i<n;i++){
            if(nums[i-1]>nums[i]){
                count++;
            }
        }
        if(nums[n-1]>nums[0]){
            count++;
        } 
        return count<=1;       
    }

     





int main(){
   vector <int> arr1 {3,4,5,1,2};
   
  
    display(arr1); 
    cout<<boolalpha;
    cout<<check(arr1);
  

}