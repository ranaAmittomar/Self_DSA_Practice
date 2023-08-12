
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include <string>
#include <unordered_map>

using namespace std;

/// <summary>
/// Please implement a function in C++ that reverses a string
/// . Your function should take a string as input and return the reversed string.
/// </summary>

/*
void reverseString(string& str) {
    const int length = str.length();
    for (int i = 0; i < length/2; i++) {
        swap(str[i], str[length - i - 1]);
    }
}
*/
/*
* print pattern as 
* 1234
* 1234
* 1234
* 1234
void printingPattern(int n) {
    int i = 0;
    while (i <= n) {
        int j = 1;
        while (j <= n) {
            cout << j;
            j++;
        }
        cout << endl;
        i++;
    }
}
*
*/
/*
* printing 
  4321
* 4321
* 4321
* void printingPattern2(int n) {
    int i = 1;
    while (i <=n) {
        int j = n;
        while (j >= 1) {
            cout << j;
            j--;
        }
        cout << endl;
        i++;
    }
}
*/
/*
* printing
* 123
* 456
* 789
void printingPattern3(int n) {
    int i = 1;
    int count = 1;
    while (i <= n) {
        int j = 1;
        while (j <=n ) {
            cout << count<<" ";
            count++;
            j++;
        }
        cout << endl;
        i++;
    }
}
*/
/*
* printing
    *
    * *
    * * *
    * * * *
    * void printingStar(int n) {
    int row = 1;
    while (row <= n) {

        int col = 1;
        while (col<=row)
        {
            cout << "*" << " ";
            col++;
        }
        cout << endl;
        row++;
    }
}
*/ 

//TRIE DATASTRUCTURE EXAMPLE ...

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->isEndOfWord;
    }
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
};




int main()
{
   /*
    * string str = "amittomar";
    reverseString(str);
    cout << str;
    */
   //all pattern printing function are below!
   /*
    printingPattern(n);
    printingPattern2(n);
    printingPattern3(n);
    printingStar(n);
    */
   
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");

    cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not found") << endl;
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not found") << endl;
    cout << "Search 'ban': " << (trie.search("ban") ? "Found" : "Not found") << endl;
    cout << "Starts with 'app': " << (trie.startsWith("app") ? "Yes" : "No") << endl;
    cout << "Starts with 'ban': " << (trie.startsWith("ban") ? "Yes" : "No") << endl;
    cout << "Starts with 'ana': " << (trie.startsWith("ana") ? "Yes" : "No") << endl;

    return 0;
}

