#include <bits/stdc++.h>
using namespace std;
// Impletion of Trie

class TrieNode{
    public:
    char data;
    //create a array which can have 26 alphabetic letter in it 
    TrieNode * children[26];
   //Terminal Node tO Check If its is Lats Node
    bool isTerminal;
   //constructor
    TrieNode(char Data){
        data = Data;
        for (int i = 0; i < 26; i++)
        {//Sara Pointer Ko Null Kar Do
            children[i] =NULL;
        }
        isTerminal =false;
    }
};

class Trie{
    private:
    TrieNode * root;
    //constructor
    
    public:
    Trie(){
        root = new TrieNode('\0');
        //Constructor call kar do trieNode ka aur by dfault NULL char pas kar do
    }
   
    //functions
 
     void insertUtil(TrieNode * root ,string word){
         //base case
        if(word.length() == 0){
            root->isTerminal =true;
            return;
        }
         int index = word[0] -'A';
        //create a child node 

        TrieNode * child;

        if(root->children[index] != NULL){
            child = root->children[index];
            //In This case Letter is present in the array 
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //Recursion 
        insertUtil(child, word.substr(1));

    
    }
    
    void insertWord(string Word){
        insertUtil(root,Word);
    }
   
    bool searchUtility(TrieNode * root ,string word){
        //base case
    if(word.length() == 0){
        return root->isTerminal;
        //kya ya terminal node ha
    }
    
        //word check karo
       
            
      int index = word[0] -'A';

      
       
     //create a child node 

        TrieNode * child;

        if(root->children[index] != NULL){
            child = root->children[index];
            //In This case Letter is present in the array 
        }
        else{
           //absent 
           return false;
        }
        //Recursion call
        return searchUtility(child,word.substr(1));

        
    }

    //search  function
    bool search(string word){
        return searchUtility(root,word);
    }
    
    void removeUtil(TrieNode * root ,string word){
         //base case
        if(word.length() == 0){
            root->isTerminal =false;
            return;
        }
         int index = word[0] -'A';
        //create a child node 

        TrieNode * child;

        if(root->children[index] != NULL){
            child = root->children[index];
            //In This case Letter is present in the array 
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //Recursion 
        removeUtil(child, word.substr(1));

    
    }
    void remove(string word){
        removeUtil(root,word);
    }

    
    

};



       



int main(){
    Trie * t =new Trie();
   
    t->insertWord("AYUSH");
    t->insertWord("TIME");

    cout<<boolalpha;
    cout<<t->search("AYUSH")<<endl;
    t->remove("AYUSH");
    cout<<t->search("AYUSH")<<endl;


}