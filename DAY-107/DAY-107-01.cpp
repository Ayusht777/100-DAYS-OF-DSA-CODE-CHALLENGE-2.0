
#include <bits/stdc++.h> 
#include<vector>

//PRIME NUMBER 

//204. Count Primes using (Sieve of Eratosthenes)
// 204. Count Primes using (Segmented Sieve)
//https://leetcode.com/problems/count-primes/description/

using namespace std;
bool isprime(int n){
   if(n<=1){
      return false;
      //prime nhai hai
   }
   for(int i=2;i<n;i++){
      if(n%i==0){
         return false;
       // gara condition shai hoja ti hai to prime number hai 
      }
   }
   return true;
}

 int countPrimes(int n) {
       std::vector <bool> prime (n,false);
        //  here we are createing a vector which have all value to false
        int count=0;
        for(int i =2;i<n;i++){
            if(prime[i]){
                continue; 
                //skip this number
            }
            count++;
            for(long multi =(long)i*i;multi<n;multi = multi+i){
                prime[multi] =true;
            }

        }
        return count;
        
    }

int countPrimess(int n) {
        //sgemnetd sieve
        ///https://leetcode.com/problems/count-primes/solutions/2145627/c-seive-of-eratosthenes-competitive-programming-segmented-seive/
        vector <bool> prime (n+1,true);
        //  here we are createing a vector which have all value totrue
        prime[0] =prime[1] =false;
        //inlo flase kar do
        int count=0;
        for(int i =2;i*i<n;i++){
            if(prime[i]==true){
               for(int j =i*i;j<=n;j = j+i){
                prime[j] =false;
            }
  
            }
          
           
        }
        for(int i =2;i<n;i++){
            if(prime[i]==true){
                count++;
            }
        }
        return count;
        
    }








int main(){
   int x ;
   cin>>x;
   if(isprime(x))
{
   cout<<"it is a prime"<<endl;
}   
   else{
      cout<<"not a prime number"<<endl;
   }



   cout<<countPrimes(10)<<endl;

}