
#include <bits/stdc++.h> 
//283. Move Zeroes 
// Move Zeroes To End 

// https://leetcode.com/problems/move-zeroes/description/


using namespace std;
void display(vector <int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";

    }
    cout<<endl;
}


void moveZeroes(vector<int>& nums) {
      int j =0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        
    }



int main(){
   vector <int> arr1 {1,0,3,4,0};
   
  
    display(arr1);
    moveZeroes(arr1);
    display(arr1);
   

}