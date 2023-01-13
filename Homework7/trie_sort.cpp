// C++ implementation to sort an array 
// of strings using Trie 
#include <bits/stdc++.h> 
using namespace std; 
  
const int MAX_CHAR = 26; 
  
struct Trie { 
  
    // 'index' vectors size is greater than  
    // 0 when node/ is a leaf node, otherwise 
    // size is 0; 
    vector<int> index; 
  
    Trie* child[MAX_CHAR]; 
  
    /*to make new trie*/
    Trie() 
    { 
        // initializing fields 
        for (int i = 0; i < MAX_CHAR; i++) 
            child[i] = NULL; 
    } 
}; 
  
// function to insert a string in trie 
void insert(Trie* root, string str, int index) 
{ 
    Trie* node = root; 
  
    for (unsigned int i = 0; i < str.size(); i++) { 
  
        // taking ascii value to find index of 
        // child node 
        char ind = str[i] - 'a'; 
  
        // making a new path if not already 
        if (!node->child[ind]) 
            node->child[ind] = new Trie(); 
  
        // go to next node 
        node = node->child[ind]; 
    } 
  
    // Mark leaf (end of string) and store 
    // index of 'str' in index[] 
    (node->index).push_back(index); 
} 
  
// function for preorder traversal of trie 
void preorder(Trie* node, string arr[]) 
{ 
    // if node is empty 
    if (node == NULL) 
        return; 
  
    for (int i = 0; i < MAX_CHAR; i++) { 
        if (node->child[i] != NULL) { 
  
            // if leaf node then print all the strings 
            // for (node->child[i]->index).size() > 0) 
            for (unsigned int j = 0; j < (node->child[i]->index).size(); j++) 
                cout << arr[node->child[i]->index[j]] << " "; 
  
            preorder(node->child[i], arr); 
        } 
    } 
} 
  
// function to sort an array 
// of strings using Trie 
void printSorted(string arr[], int n) 
{ 
    Trie* root = new Trie(); 
  
    // insert all strings of dictionary into trie 
    for (int i = 0; i < n; i++) 
        insert(root, arr[i], i); 
  
    // print strings in lexicographic order 
    preorder(root, arr); 
} 
  

int main() 
{ 
    string arr[] = { "word", "category", "cat", "new", "news", "world", "bear", "at", "work", "time" }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    printSorted(arr, n); 
    return 0; 
} 