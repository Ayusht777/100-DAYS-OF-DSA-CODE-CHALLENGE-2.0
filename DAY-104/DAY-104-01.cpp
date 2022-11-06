
#include <bits/stdc++.h> 
// Check If The String Is A Palindrome 
//https://www.codingninjas.com/codestudio/problems/check-if-the-string-is-a-palindrome_1062633?leftPanelTab=0


using namespace std;
void display(vector <int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";

    }
    cout<<endl;
}



bool checkPalindrome(string s)
{
   string str;
   for(int i = 0; i<s.length(); i++)
   {
       if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')           || (s[i]>='0' && s[i]<='9') )
       {
           str.push_back(s[i]);
       }
   }
   
   int i =0;
   int j = str.length()-1;
   
   while(i<j)
   {
       if(str[i]>='A' && str[i]<='Z')
       {
           str[i]=str[i] -'A'+'a';
       }
       
       if(str[j]>='A' && str[j]<='Z')
       {
           str[j]=str[j] -'A'+'a';
       }
       
       if(str[i++] != str[j--])
       {
           return 0;
       }
   }
   
   return 1;
}

 
     





int main(){
   

}