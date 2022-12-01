#include <bits/stdc++.h> 
using namespace std;
//Interleave The First Half Of The Queue With The Second Half 
//https://www.codingninjas.com/codestudio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450
void interLeaveQueue(queue < int > & q) {
      if(q.size()%2!=0){

          return;
      }
        //to gey mid of this queue
       int half = q.size()/2;
        queue <int> nq;
       while(q.size()!=half){
           nq.push(q.front());
           q.pop();
       }
       // abha 2 queue half hogyi hai
      
       while(!nq.empty()){
           q.push(nq.front());
           nq.pop();
           q.push(q.front());
           q.pop();
       }
       
       
    
}
void print( queue <int> &q){
 
  if(q.empty()){
    cout<<"it is empty"<<endl;
  }
  
  else{
    queue <int> qx =q; //copy
    while(!q.empty()){
       cout<<q.front()<<" ";
       q.pop();

    }
    cout<<endl;
    q =qx;

  }

}

int main(){
  queue <int> q;
  for (size_t i = 1; i < 9; i++)
  {
    q.push(i);//8 elemnts

  }
  cout<<"Front element of this queue "<<q.front() << " ans size of this queue "<<q.size()<<endl;
  cout<<"___________________________________________________________________________________"<<endl;
  print(q);
   interLeaveQueue(q);
 print(q);


   return 0;
}