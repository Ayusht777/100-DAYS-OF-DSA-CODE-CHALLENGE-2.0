#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//Next Smaller Element 
//https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?leftPanelTab=0
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack <int> s;
    s.push(-1);
    
    vector <int> ans(n);
    
    for(int i=n-1;i>=0;i--){
        int curr =arr[i];
        while(s.top()>=curr){
            s.pop();
        }
        //ans is stack ka top ma
        ans[i] =s.top();
        ans[i] =s.top();
        s.push(curr);
    }
    return ans;
}