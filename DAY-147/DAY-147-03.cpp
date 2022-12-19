#include <bits/stdc++.h>
using namespace std;
// Longest Common Prefix 
// https://www.codingninjas.com/codestudio/problems/longest-common-prefix_2090383?leftPanelTab=0

#include <bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    
    //for traversing all characters of first string
    for(int i = 0;i<arr[0].length();i++){
        char ch = arr[0][i];
        //store first char of the first element form this array
        bool match = true;
         
        //for comparing ch with rest os the strings
        //we started loop from 1 because we have to compare
        //with another element of a this array
        for(int j=1;j<n;j++){
            //not match
            if(arr[j].size() < i || ch != arr[j][i]){
                //array ka first element ka string 
                // ka first char ko compare karo
                match = false;
                break;
            }
           
        }
        //iska bada  loop ka bada match false hogha ek char ka liya
        if(match == false)
            break;
        
        else
            ans.push_back(ch);

    }
    return ans;
}