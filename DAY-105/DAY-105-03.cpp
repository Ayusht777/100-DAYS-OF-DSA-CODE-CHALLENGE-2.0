
#include <bits/stdc++.h> 

using namespace std;
//Replace Spaces 
//https://www.codingninjas.com/codestudio/problems/replace-spaces_1172172?leftPanelTab=0

string replaceSpaces(string &str){
    // Write your code here.
  
        string temp="";
        
        for(int i=0;i<str.length();i++){
            if(str[i]==' '){
                temp.push_back('@');
                temp.push_back('4');
                temp.push_back('0');
            }
            else{
             temp.push_back(str[i]);   
            }
                            
        }
  
     return temp;

}
string replaceSpaces1(string &str){
    // Write your code here.
  
        
        for(int i=0;i<str.length();i++){
            if(str[i]==' '){
                str.replace(i,1,"@40");
               
            }
                      
        }
  
     return str;

}


     





int main(){
    string x = "test sample";
    cout<<x<<endl;
    cout<<replaceSpaces1(x)<<endl;

}