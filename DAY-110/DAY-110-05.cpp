
#include <bits/stdc++.h> 

using namespace std;
//Reverse a String using recursion
void ReverseAstring(string &s,int i,int j){
  //base case
  if(i>j){
    return ;
  }

  swap(s[i++],s[j--]);
  

  return(ReverseAstring(s,i,j));


  
  }

  




int main(){

  string a ="ayush";
  cout<<a<<endl;
  ReverseAstring(a,0,a.length()-1);
  cout<<a<<endl;
 
 


}