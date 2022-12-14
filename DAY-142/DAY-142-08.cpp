#include <bits/stdc++.h>

using namespace std;

// Kth largest element 
//https://www.codingninjas.com/codestudio/problems/kth-largest-element_796007?leftPanelTab=0

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector < int>, greater < int>> q;

       //step 1 : sraha k element min heap ma dalo
    for (int i = 0; i < k; i++)
    {
        q.push(nums[i]);
    }

       //step 2 : remaing k elemnet ma sa largest elemnent q ma dalo
    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] > q.top())
        {
            q.pop();
            q.push(nums[i]);
        }
    }

       //step 3 : ans at top

    int ans = q.top();

    return ans;

 }