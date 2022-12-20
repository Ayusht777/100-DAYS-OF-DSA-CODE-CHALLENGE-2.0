#include <bits/stdc++.h>
using namespace std;
// Implement a phone directory 
// https://www.codingninjas.com/codestudio/problems/implement-a-phone-directory_1062666?leftPanelTab=0

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
         int index = word[0] -'a';
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
    void printSuggestions(TrieNode * curr,vector<string> & temp,string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
            
        }
        for(char ch ='a';ch<= 'z';ch++){
            TrieNode * next = curr->children[ch-'a'];
            
            if(next !=NULL){
                prefix.push_back(ch);
                printSuggestions(next,temp,prefix);
                prefix.pop_back();
                
            }
        }
    }
    vector<vector<string>> getSuggestions(string str){
        TrieNode* prev =root;
        vector<vector<string>> output;
        string prefix = "";
        
        for(int i =0;i<str.length();i++){
            char lastch = str[i];
            prefix.push_back(lastch);
            //check for lastch
            TrieNode * curr = prev->children[lastch - 'a'];
            //if not found
            if(curr ==NULL){
                break;
            }
            //if found
            vector<string> temp;
            printSuggestions(curr,temp,prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr;
            
            
        }
        return output;
        
    }
    
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
   //creation of trie
    Trie * t = new Trie();
    
   //insert all contact in trie
    for(int i=0;i<contactList.size();i++){
        string str = contactList[i];
        t->insertWord(str);
    }
    
    //return ans
    
    return t->getSuggestions(queryStr);
}