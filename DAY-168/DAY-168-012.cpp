#include <bits/stdc++.h>
using namespace std;
//801. Minimum Swaps To Make Sequences Increasing(Space optimization)
//https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

class Solution {
public:
    int solveSO(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size();
        int swapx = 0;
        int noswapx = 0;
        int currswap = 0;
        int nocurrswap = 0;

        for (int index = n - 1; index >= 1; index--) {
            for (int swapped = 1; swapped >= 0; swapped--) {
                int ans = INT_MAX;
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                // catch
                if (swapped == 1) {
                    swap(prev1, prev2);
                }
                // noswap
                if (nums1[index] > prev1 && nums2[index] > prev2) {
                    ans = noswapx;
                }
                // swapped case
                if (nums1[index] > prev2 && nums2[index] > prev1) {
                    ans = min(ans, 1 + swapx);
                }
                if (swapped) {
                    currswap = ans;
                }
                else {
                    nocurrswap = ans;
                }
            }
            swapx = currswap;
            noswapx = nocurrswap;
        }
        return min(swapx, noswapx);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2)
    {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        // it means previous index is swapped
        bool swapped = 0;
        return solveSO(nums1, nums2);
    }
};