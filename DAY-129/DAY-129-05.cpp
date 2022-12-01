#include <bits/stdc++.h> 
using namespace std;
//implement k Queues in a single array?
class kqueue{
  
     int n;
     int k;
     int freespot;
     //arrs
     int *front;
     int *rear;
     int *arr;
     int *next;

     public:
     kqueue(int n,int k){
      this->n = n;
      this->k = k;
      //dynaic arr
      arr = new int [n];
      front =new int[k];
      rear =new int[k];
      next = new int[n];
      freespot=0;

      //front and rear to -1
      for (size_t i = 0; i < k; i++)
      {
        front[i] =-1;
      }
      for (size_t i = 0; i < k; i++)
      {
        rear[i] =-1;
      }

      //next array index
      for (size_t i = 0; i < n; i++)
      {
        next[i] =i+1;

      }
      next[n-1] =-1;

       
        

      
     } 

     void push(int data ,int qi){
      //overflow condition

      if(freespot==-1){
        cout<<"Queue is overflow";
        return;
      }
      //find first free index 
      int i =freespot;
      //freespot ko update;
      freespot =next[i];
      //check first element
      if(front[qi-1]==-1){
        //first index ka liye
        front[qi-1] =i;
      }
      else{
        //link next element to pervoius element
        next[rear[qi-1]] =i;
      }
      //update next
      next[i] =-1;
      //update rear
      rear[qi-1] = i;

      //push elemnet

      arr[i] = data;

     }

     int pop(int qi){
      //underflow
      if(front[qi-1]==-1){
        cout<<"Queue underflow"<<endl;
        return -1;
      }
      //find index to pop 
      int i  =front[qi-1];

      //front ko aaage badho
      front[qi-1] =next[i];

      //freeslost ko manage karo

      next[i] =freespot;
      freespot =i;
      return arr[i];


     }

      

};

int main(){
  kqueue q(10,3);

  q.push(11,1);
  q.push(15,2);
  q.push(25,1);
  q.push(22,2);


cout<<q.pop(1)<<endl;




}