
#include <bits/stdc++.h> 
//189. Rotate Array

//https://leetcode.com/problems/rotate-array/description/

using namespace std;
void display(vector <int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";

    }
    cout<<endl;
}

 void rotate(vector<int>& nums, int k) {
        vector <int> temp(nums.size());
        for(int i =0;i<nums.size();i++)
        {
            temp[(i+k)%nums.size()] =nums[i];
        }
        nums =temp;
    }






int main(){
   vector <int> arr1 {1,0,3,4,0};
   
  
    display(arr1);
    rotate(arr1,2);
    display(arr1);
   

}