#include <bits/stdc++.h> 

#include<vector>
using namespace std;
//Check if Linked List is Palindrome
//https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool check(vector <int> x){
        int s =0;
        int e =x.size()-1;
        while(s<=e){
            
           if(x[s]!=x[e]){
               return 0;
           }
           s++;
           e--;
        }
        return 1;
        
        
    }
    bool isPalindrome(Node *head)
    {
       vector <int> ans;
       Node * temp =head;
       while(temp!=NULL){
           ans.push_back(temp->data);
           temp =temp->next;
       }
       
       return (check(ans));
    }
};