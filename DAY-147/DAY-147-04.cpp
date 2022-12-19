#include <bits/stdc++.h>
using namespace std;
// Longest Common Prefix (using Trie) 
// https://www.codingninjas.com/codestudio/problems/longest-common-prefix_2090383?leftPanelTab=0

class TrieNode {
  public: char data;

  TrieNode * children[26];

  bool isTerminal;

  int childcount;
  TrieNode(char Data) {
    data = Data;
    for (int i = 0; i < 26; i++) { //Sara Pointer Ko Null Kar Do
      children[i] = NULL;
    }
    isTerminal = false;
    childcount = 0;
  }
};

class Trie {
  private: TrieNode * root;
  //constructor

  public: Trie(char ch) {
    root = new TrieNode(ch);

  }

  void insertUtil(TrieNode * root, string word) {
    //base case
    if (word.length() == 0) {
      root -> isTerminal = true;
      return;
    }
    int index = word[0] - 'a';
    //create a child node 

    TrieNode * child;

    if (root -> children[index] != NULL) {
      child = root -> children[index];
      //In This case Letter is present in the array 
    } else {
      child = new TrieNode(word[0]);
      root -> childcount++;
      root -> children[index] = child;
    }

    //Recursion 
    insertUtil(child, word.substr(1));

  }

  void insertWord(string Word) {
    insertUtil(root, Word);
  }

  void lcp(string str, string & ans) {
    for (int i = 0; i < str.length(); i++) {
      char ch = str[i];

      if (root -> childcount == 1) {
        ans.push_back(ch);
        int index = ch - 'a';
        root = root -> children[index];
      } else {
        break;
      }

      if (root -> isTerminal) {
        break;
      }
    }

  }

};

string longestCommonPrefix(vector < string > & arr, int n) {
  Trie * t = new Trie('\0');
  //insert kardo all strings into trie
  for (int i = 0; i < n; i++) {
    t -> insertWord(arr[i]);
  }
  string first = arr[0];
  string ans = "";
  t -> lcp(first, ans);

  return ans;
} 