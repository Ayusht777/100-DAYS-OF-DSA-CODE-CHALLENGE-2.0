
#include <bits/stdc++.h> 
//240. Search a 2D Matrix II
//https://leetcode.com/problems/search-a-2d-matrix-ii/description/
using namespace std;
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r =matrix.size();
        int c= matrix[0].size();

        int startr = 0;
        int endc = c-1;
        while(startr<r &&endc >=0){
            int element = matrix[startr][endc];
            if(element ==target){
                return 1;
            }
            if(element<target){
                startr++;
            }
            else{
                endc--;
            }

   
        }
        return 0;
        
    }

int main(){

   vector<vector<int>> v {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
   cout<<boolalpha;
    cout<<searchMatrix(v,11);

   
}