#include <bits/stdc++.h>
using namespace std;
//85. Maximal Rectangle
//https://leetcode.com/problems/maximal-rectangle/
class Solution {
public:
     vector<int> nextSmallerElement(vector<int> arr, int n){
         stack<int> s;
         s.push(-1);
         vector<int> ans(n);
         
         for(int i=n-1;i>=0;i--){
             int curr = arr[i];
             while(s.top()!= -1 && arr[s.top()]>= curr){
                 s.pop();
             }
             ans[i] = s.top();
             s.push(i);
         }
         return ans;
     } 
         vector<int> prevSmallerElement(vector<int> arr, int n){
         stack<int> s;
         s.push(-1);
         vector<int> ans(n);
         
         for(int i= 0; i<n;i++){
             int curr = arr[i];
             while(s.top()!= -1 && arr[s.top()]>= curr){
                 s.pop();
             }
             ans[i] = s.top();
             s.push(i);
         }
         return ans;
     } 

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights,n);
        
        vector <int> prev(n);
        prev = prevSmallerElement(heights,n);
        
        int area = INT_MIN;
        for(int i=0; i<n ; i++ ){
            int l = heights[i];
            
            
            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] -1;
            int newArea = l*b;
            area = max(area,newArea);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {       int n=matrix.size();
    //     int m=matrix[0].size();
    //     vector<vector<int>> matrix1(n,vector<int>(m,0));
    //    for(int i=0;i<n;i++){
    //        for(int j=0;j<m;j++){
    //            if(matrix[i][j]=='1')
    //               matrix1[i][j]=1;
    //             else
    //                matrix1[i][j]=0;
    //        }
    //    }
    //    cout<<matrix1[0][0];
    //    int maxarea=-1;
    //    for(int i=0;i<n;i++){
    //        int newarea=largestRectangleArea(matrix1[i]);
    //        cout<<newarea<<endl;
    //        if(i!=n-1 ){
    //            for(int j=0;j<m;j++){
    //                if(matrix1[i+1][j]!=0){
    //                    matrix1[i+1][j]=matrix1[i+1][j]+matrix[i][j];
    //                }
    //            }
    //        }
    //        maxarea=max(maxarea,newarea);
    //    }
    int row=matrix.size();
    int column=matrix[0].size();
     vector<int> histogram(column);
     int maxarea=0;
     for(int i=0;i<row;i++){
         for(int j=0;j<column;j++){
             if(matrix[i][j]=='1'){
                 histogram[j]+=1;
             }
             else{
                histogram[j]=0;
             }
         }
         maxarea=max(maxarea,largestRectangleArea(histogram));

     }
      

      return maxarea;
    //    int m=matrix.size();
    //     if(m==0) return 0;
    //     // int n=matrix[0].size(), result=0;
    //     vector<int> histogram(n, 0);
        
    //     for(int i=0; i<m; i++){
    //         for(int j=0; j<n; j++){
    //             if(matrix[i][j]=='1')
    //                 histogram[j]+=1;
    //             else
    //                 histogram[j]=0;
    //         }
            
    //         result = max(result, largestArea(histogram));
    //         cout<<result<<" ";
    //     }
    //     return result;
    }
};