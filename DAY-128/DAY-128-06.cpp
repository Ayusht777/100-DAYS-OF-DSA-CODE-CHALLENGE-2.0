#include <bits/stdc++.h>

using namespace std;

//Circular tour
//https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

struct petrolPump
{
    int petrol;
    int distance;
};
class Solution {
   public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n) {
        int deficit = 0;
        int balance = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            balance = balance + p[i].petrol - p[i].distance;
            if (balance < 0) {
                // balance negtive yahni ki pertol kam hai
                deficit = deficit + balance;
                start = i + 1;
                balance = 0;
            }
        }
        if (deficit + balance > 0) {
            return start;
        } else {
            return -1;
        }
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}