
#include <bits/stdc++.h> 


//Check Palindrome 
//https://www.codingninjas.com/codestudio/problems/check-palindrome_4219630?leftPanelTab=0
using namespace std;
//Check a String if Palindrome   using recursion

bool CheckifPalindrome(string s,int i,int j){
  if(i>j){
    return true;
  }

  if(s[i]!=s[j]){
    return false;
  }
else{
  return (CheckifPalindrome(s,i+1,j-1));
}




}


  




int main(){

  string a ="abbccbba";
 bool c =CheckifPalindrome(a,0,a.length()-1);
  if(c){
    cout<<"palindrome";


  }

  else{
    cout<<"noT "<<endl;
  }

  
 
 
 


}