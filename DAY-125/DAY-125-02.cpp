#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<limits.h>
#define MAX 100
// Max rectangle
//https://practice.geeksforgeeks.org/problems/max-rectangle/1
class Solution{
  private:
 
  //logi largets are ain histigrram
  vector < int > nextSmallerElement(int *arr, int n) {
            stack < int > s;
            s.push(-1);

            vector < int > ans(n);

            for (int i = n - 1; i >= 0; i--) {
                int curr = arr[i];
                while (s.top() != -1 && arr[s.top()] >= curr) {
                    s.pop();
                }
                //ans is stack ka top ma
                ans[i] = s.top();
                s.push(i);
            }
            return ans;

        }
    vector < int > pervSmallerElement(int * arr, int n) {

        stack < int > s;
        s.push(-1);

        vector < int > ans(n);

        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            //ans is stack ka top ma
            ans[i] = s.top();
            s.push(i);
        }
        return ans;

    }
    
    int largestRectangleArea(int *heights ,int n) {
            // int n = heights.size();
            //grpha ki height 

            vector < int > next(n);
            next = nextSmallerElement(heights, n);

            vector < int > perv(n);
            perv = pervSmallerElement(heights, n);

            int area = INT_MIN;

            for (int i = 0; i < n; i++) {
                int l = heights[i];

                //ki next -1 hojya mtlb ki height sab sam ha to with bhi height ki size hogi
                if (next[i] == -1) {
                    next[i] = n;
                }
                int b = next[i] - perv[i] - 1;
                int newArea = l * b;
                area = max(area, newArea);
            }

            return area;

        }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // commpute area first row
        int area = largestRectangleArea(M[0],m);
        
        
        for(int i =1;i<n;i++){
            for(int j=0;j<m;j++){
                //row  update by adding perviosu row 
                if(M[i][j]!=0){
                  M[i][j] =M[i][j] + M[i-1][j];
                }
                else{
                     M[i][j]  =0;
                     
                     
                     
                }
                
               
            }
             // entrie roe update
                area = max(area,largestRectangleArea(M[i],m));
            
           
        }
         return area;
    }
};
using namespace std;
//Max rectangle
//https://practice.geeksforgeeks.org/problems/max-rectangle/1


    class Solution{
  private:
  
  //logi largets are ain histigrram
  vector < int > nextSmallerElement(int *arr, int n) {
            stack < int > s;
            s.push(-1);

            vector < int > ans(n);

            for (int i = n - 1; i >= 0; i--) {
                int curr = arr[i];
                while (s.top() != -1 && arr[s.top()] >= curr) {
                    s.pop();
                }
                //ans is stack ka top ma
                ans[i] = s.top();
                s.push(i);
            }
            return ans;

        }
    vector < int > pervSmallerElement(int * arr, int n) {

        stack < int > s;
        s.push(-1);

        vector < int > ans(n);

        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            //ans is stack ka top ma
            ans[i] = s.top();
            s.push(i);
        }
        return ans;

    }
    
    int largestRectangleArea(int *heights ,int n) {
            // int n = heights.size();
            //grpha ki height 

            vector < int > next(n);
            next = nextSmallerElement(heights, n);

            vector < int > perv(n);
            perv = pervSmallerElement(heights, n);

            int area = INT_MIN;

            for (int i = 0; i < n; i++) {
                int l = heights[i];

                //ki next -1 hojya mtlb ki height sab sam ha to with bhi height ki size hogi
                if (next[i] == -1) {
                    next[i] = n;
                }
                int b = next[i] - perv[i] - 1;
                int newArea = l * b;
                area = max(area, newArea);
            }

            return area;

        }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // commpute area first row
        int area = largestRectangleArea(M[0],m);
        
        
        for(int i =1;i<n;i++){
            for(int j=0;j<m;j++){
                //row  update by adding perviosu row 
                if(M[i][j]!=0){
                  M[i][j] =M[i][j] + M[i-1][j];
                }
                else{
                     M[i][j]  =0;
                     
                     
                     
                }
                
               
            }
             // entrie roe update
                area = max(area,largestRectangleArea(M[i],m));
            
           
        }
         return area;
    }
};




    


