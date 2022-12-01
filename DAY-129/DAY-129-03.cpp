#include <bits/stdc++.h> 
using namespace std;
//Interleave The First Half Of The Queue With The Second Half 
//TLE MAR RHA HAI
//https://www.codingninjas.com/codestudio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450
void interLeaveQueue(queue < int > & q) {
      if(q.size()%2!=0){

          exit(1);
      }
        //to gey mid of this queue
       int half = q.size()/2;
       stack <int> s;
       while(q.size()!=half){
           s.push(q.front());
           q.pop();
       }
       // the queue will be goint to half the size
       while(!s.empty()){
           q.push(s.top());
           s.pop();
       }
       half = q.size()/2;
       while(q.size()!=half){
           q.push(q.front());
           q.pop();
       }
       half = q.size()/2;
       while(q.size()!=half){
           s.push(q.front());
           q.pop();
       }
       //wapsi queue ma dal do
       while(!s.empty()){
           int val = s.top();
           s.pop();
           q.push(val);
           val = q.front();
           q.push(val);
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