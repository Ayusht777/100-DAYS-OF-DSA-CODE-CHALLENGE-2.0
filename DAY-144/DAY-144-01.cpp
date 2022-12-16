#include <bits/stdc++.h>
using namespace std;
// K-th Largest Sum Subarray (Brute-Force)
// https://www.codingninjas.com/codestudio/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0


int getKthLargest(vector<int> &arr, int k)
{
	 vector<int> ans;
        for(int i=0;i<arr.size();i++){
            int sum =0;
            for(int j=i;j<arr.size();j++){
                sum = sum + arr[j];
                ans.push_back(sum);
            }
            
        }
        
        //sorted it 
        
        sort(ans.begin(),ans.end());
        
        return(ans[ans.size()-k]);
}
