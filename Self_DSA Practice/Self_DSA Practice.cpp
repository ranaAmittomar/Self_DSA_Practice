
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

/*

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


*/

//HEAP DATA STRUCTURE EXAMPLE...
/*
class MinHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int minIndex = i;
        int l = leftChild(i);
        int r = rightChild(i);

        if (l < heap.size() && heap[l] < heap[minIndex]) {
            minIndex = l;
        }
        if (r < heap.size() && heap[r] < heap[minIndex]) {
            minIndex = r;
        }

        if (i != minIndex) {
            swap(heap[i], heap[minIndex]);
            heapifyDown(minIndex);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int getMin() {
        return heap[0];
    }

    void extractMin() {
        if (heap.empty()) {
            return;
        }
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapifyDown(0);
    }
};

*/

//REVERSE A LINKED LIST..

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }
    void insertData(int val) {
        Node* newNode = new Node(val);//initailizing new Node.
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    void reverseList() {
        Node* prev = NULL;
        Node* current = head;
        Node* nextNode;
        while (current != NULL) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
    }
    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
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
    /*
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

    */

    /*
    MinHeap minHeap;

    minHeap.insert(5);
    minHeap.insert(10);
    minHeap.insert(3);
    minHeap.insert(8);
    minHeap.insert(2);

    cout << "Minimum element: " << minHeap.getMin() << endl;

    minHeap.extractMin();

    cout << "Minimum element after extraction: " << minHeap.getMin() << endl;
    */

    LinkedList myList;
    myList.insertData(2);
    myList.insertData(4);
    myList.insertData(6);
    cout << "The original List :- ";
    myList.display();
    myList.reverseList();
    cout << "The reversed List :- ";
    myList.display();

    return 0;
}

