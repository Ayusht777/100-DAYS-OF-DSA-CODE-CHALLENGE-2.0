#include <bits/stdc++.h>
using namespace std;
// Implement Trie 
// https://www.codingninjas.com/codestudio/problems/implement-trie_631356?leftPanelTab=0

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class TrieNode
{
  public: char data;
     //create a array which can have 26 alphabetic letter in it 
  TrieNode *children[26];
     //Terminal Node tO Check If its is Lats Node
  bool isTerminal;
     //constructor
  TrieNode(char Data)
  {
    data = Data;
    for (int i = 0; i < 26; i++)
    {
        //Sara Pointer Ko Null Kar Do
      children[i] = NULL;
    }

    isTerminal = false;
  }
};

class Trie
{
  TrieNode * root;
  public:

    /**Initialize your data structure here. */
    Trie()
    {
      root = new TrieNode('\0');
    }

  void insertUtil(TrieNode *root, string word)
  {
       //base case
    if (word.length() == 0)
    {
      root->isTerminal = true;
      return;
    }

    int index = word[0] - 'a';
       //create a child node 

    TrieNode * child;

    if (root->children[index] != NULL)
    {
      child = root->children[index];
         //In This case Letter is present in the array 
    }
    else
    {
      child = new TrieNode(word[0]);
      root->children[index] = child;
    }

       //Recursion 
    insertUtil(child, word.substr(1));
  }

  bool searchUtility(TrieNode *root, string word)
  {
       //base case
    if (word.length() == 0)
    {
      return root->isTerminal;
         //kya ya terminal node ha
    }

       //word check karo

    int index = word[0] - 'a';

       //create a child node 

    TrieNode * child;

    if (root->children[index] != NULL)
    {
      child = root->children[index];
         //In This case Letter is present in the array 
    }
    else
    {
         //absent 
      return false;
    }

       //Recursion call
    return searchUtility(child, word.substr(1));
  }

  /**Inserts a word into the trie. */
  void insert(string word)
  {
    insertUtil(root, word);
  }

  /**Returns if the word is in the trie. */
  bool search(string word)
  {
    return searchUtility(root, word);
  }

  bool prefixUtility(TrieNode *root, string word)
  {
       //base case
    if (word.length() == 0)
    {
      return true;
         //kya ya terminal node ha
    }

       //word check karo

    int index = word[0] - 'a';

       //create a child node 

    TrieNode * child;

    if (root->children[index] != NULL)
    {
      child = root->children[index];
         //In This case Letter is present in the array 
    }
    else
    {
         //absent 
      return false;
    }

       //Recursion call
    return prefixUtility(child, word.substr(1));
  }

  /**Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix)
  {
    prefixUtility(root, prefix);
  }
};

