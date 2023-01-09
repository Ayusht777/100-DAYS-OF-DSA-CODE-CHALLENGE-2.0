#include <bits/stdc++.h>
using namespace std;
//  Nth Fibonacci Number  Using DP (Space Optimization )
// https://www.codingninjas.com/codestudio/problems/nth-fibonacci-number_74156?leftPanelTab=0

int main()
{
    int n;
    cin>>n;
    //step 1:
    int prev1 = 1;
    int prev2 = 0 ;
    //step 2:
    if(n==0){
        return 0;
    }
    //step 3 :
    for(int i=2;i<=n;i++){
        int curr = prev1 + prev2;
        //shift logic
        prev2 = prev1;
        prev1 = curr;
        
    }
    cout<<prev1<<endl;
 
} 