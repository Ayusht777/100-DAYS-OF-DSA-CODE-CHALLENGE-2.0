#include <bits/stdc++.h> 
using namespace  std;
//Subsequences of String
//https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087?leftPanelTab=1

void solve(string str,string output,int index,vector <string> &ans){
    //base case
    if(index>=str.length()){
        if(output.length()>0){
        ans.push_back(output);
        }
        return;
        
    }
    //exclude case
    solve(str,output,index+1,ans);
    //include

    char e = str[index];
    output.push_back(e);
    solve(str,output,index+1,ans);
}

vector<string> subsequences(string str){
    vector <string> ans;
    string output ="";
    int index =0;
    solve(str,output,index,ans);
    return ans;

    
}






int main() {

  
  
    


}