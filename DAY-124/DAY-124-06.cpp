#include<iostream>
#include<stack>
#include<vector>

#include<limits.h>
using namespace std;
//84. Largest Rectangle in Histogram
//https://leetcode.com/problems/largest-rectangle-in-histogram/description/
class Solution {
    private:
        vector < int > nextSmallerElement(vector < int > arr, int n) {
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
    vector < int > pervSmallerElement(vector < int > arr, int n) {

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
    public:
        int largestRectangleArea(vector < int > & heights) {
            int n = heights.size();
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
};