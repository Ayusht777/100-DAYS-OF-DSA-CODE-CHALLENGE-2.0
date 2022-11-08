
#include <bits/stdc++.h> 
//74. Search a 2D Matrix
//https://leetcode.com/problems/search-a-2d-matrix/description/
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c= matrix[0].size();
        int start =0;
        int end = r*c-1;
        int mid = start +(end-start)/2;

        while(start<=end){
            int element  = matrix[mid/c][mid%c];
            // mid / c = mid vale divid by colmun size 

            if(element==target){
                return 1;
            }
            if(element <target){
                start = mid+1;

            }
            else{
                end = mid-1;
            }
            mid = start +(end-start)/2;

        }
        return 0;
        
    }


int main(){

   vector<vector<int>> v {{1,2,3},{4,5,6},{7,8,9}};
   cout<<boolalpha;
    cout<<searchMatrix(v,5);

   
}