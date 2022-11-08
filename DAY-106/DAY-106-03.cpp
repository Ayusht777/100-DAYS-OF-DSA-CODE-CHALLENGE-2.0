
#include <bits/stdc++.h> 
//54. Spiral Matrix
///https://leetcode.com/problems/spiral-matrix/description/
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        int row =matrix.size();
        int col = matrix[0].size();
        int total = row*col;
        int count =0;

        //row/col travrers
        int sr = 0;
        int sc=0;
        int er =row-1;
        int ec = col-1;

        while(count<total){
            for(int i = sc ;i<=ec &&count<total;i++){
                ans.push_back(matrix[sr][i]);
                count++;
            }
            sr++;
             for(int i = sr ;i<=er &&count<total;i++){
                ans.push_back(matrix[i][ec]);
                count++;
            }
            ec--;
             for(int i = ec ;i>=sc &&count<total;i--){
                ans.push_back(matrix[er][i]);
                count++;
            }
            er--;
             for(int i = er ;i>=sr &&count<total;i--){
                ans.push_back(matrix[i][sc]);
                count++;
            }
            sc++;

        }
        return ans;
        
    }


int main(){

   vector<vector<int>> v {{1,2,3},{4,5,6},{7,8,9}};
  vector<int> x=  spiralOrder(v);

   for(auto i:x){
      cout<<i<<" ";
   }

}