
#include <bits/stdc++.h> 
//
//https://leetcode.com/problems/rotate-image/description/
using namespace std;
 void rotate(vector<vector<int>>& matrix) {
        int r =matrix.size();
        int c= matrix[0].size();
        vector <vector<int>> ans;
        for(int i = 0;i<c;i++){
            vector <int> m1;
            for(int j = r-1;j>=0;j--){
                m1.push_back(matrix[j][i]);
            }
            ans.push_back(m1);

        }
        matrix =ans;
    }


int main(){

   vector<vector<int>> v {{1,2,3},{4,5,6},{7,8,9}};
     rotate(v);

   
}