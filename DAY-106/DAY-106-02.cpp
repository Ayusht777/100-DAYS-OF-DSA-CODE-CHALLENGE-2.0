
#include <bits/stdc++.h> 
//  Print Like A Wave 
//https://www.codingninjas.com/codestudio/problems/print-like-a-wave_893268?leftPanelTab=0
using namespace std;
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{   
    vector <int> ans;
    for(int c=0;c<mCols;c++){
        if(c&1){
            //odd
            for(int r=nRows-1;r>=0;r--){
                cout<<arr[r][c]<<" ";
                ans.push_back(arr[r][c]);
            }
        }
        else{
            for(int r= 0;r<nRows;r++){
                cout<<arr[r][c]<<" ";
                 ans.push_back(arr[r][c]);
            }
        }

}
}


int main(){
   vector <vector<int>> arr {{9,8,3,},{4,5,6,111},{0,9,5}};
   wavePrint(arr,3,3);

}