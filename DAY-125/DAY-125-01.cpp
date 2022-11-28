#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
//The Celebrity Problem 
// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution 
{   private:
   bool knows(vector<vector<int> >& M, int a,int b,int n){
       if(M[a][b]==1){
           return true;
       }
       else{
           return false;
       }
       
       
   }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
       stack <int> s;
       
       //step 1 : push all elememt of vector in stack
       for(int i=0 ;i<n;i++){
           s.push(i);
       }
       
       //step 2 : while size !=1 matlab ek hi elmnet ho 
       
       while(s.size()> 1){
           int a =s.top();
           s.pop();
           int b = s.top();
           s.pop();
           //ki a to b ko nhi janta hai
           if(knows(M,a,b,n)){
               s.push(b);
           }
           else{
               s.push(a);
               // ki a ko ki nhi janta hai
           }
           
           
       }
       int candidate = s.top();
       //step 3 : iska matlab ki stack ma ek element hai jo ki celibrity ho skat hai
       
       // verify it
       
   
       int zerocount =0;
       
       for(int i =0;i <n;i++){
           if(M[candidate][i]==0){
               zerocount++;
           }
       }
       
       // all zeros
       if(zerocount != n){
           return -1;
       }
       
       //colcheck
       
        int oneCount =0;
       
       for(int i =0;i<n;i++){
           if(M[i][candidate]==1){
               oneCount++;
           }
       }
       
       // daigonal wali step
       
       if(oneCount!=n-1){ //matlba ki 2 bar hi one hoga colum ma 
           return -1; 
           
       }
       
           return candidate;
       
    }
};
int main(){



    


}