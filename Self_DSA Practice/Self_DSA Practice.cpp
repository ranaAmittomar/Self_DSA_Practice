
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


//Palindrome Check
bool isPalindrome(const string& word) {
    int start = 0;
    int end = word.length() - 1;
    while (start < end) {
        if (tolower(word[start]) != tolower(word[end])) { //for case sensitive

            return false;
        }
        start++;
        end--;
    }
    return true;
}


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
public: 
    Node* head; // we need to make it public if we want to access it outside of class inside main func.
public:
    LinkedList() {
        head = NULL;
    }
    Node* getHead() {
        return head;
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

    Node* findMiddle() { //fIND middle of Linked List..
        if (head == NULL) {
            return NULL;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    bool hasCycle() {
        if (head == NULL) {
            return NULL;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

LinkedList mergeSortedLL(LinkedList l1, LinkedList l2) { //merging the sorte list
    LinkedList mergeList;
    Node* curr1 = l1.getHead();
    Node* curr2 = l2.getHead();
    while (curr1 != NULL && curr2 != nullptr) {
        if (curr1->data < curr2->data) {
            mergeList.insertData(curr1->data);
            curr1 = curr1->next;
        }
        else {
            mergeList.insertData(curr2->data);
            curr2 = curr2->next;
        }
    }
    while (curr1 != nullptr) {
        mergeList.insertData(curr1->data);
        curr1 = curr1->next;
    }
    while (curr2 != nullptr) {
        mergeList.insertData(curr2->data);
        curr2 = curr2->next;
    }
    return mergeList;
}

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

   /*
    LinkedList myList;
    myList.insertData(2);
    myList.insertData(4);
    myList.insertData(6);
    myList.insertData(10);
    myList.insertData(15);
    myList.insertData(20);
    myList.insertData(NULL);
    cout << "The original List :- ";
    myList.display();
    myList.reverseList();
    cout << "The reversed List :- ";
    myList.display();

    Node* middle = myList.findMiddle();
    if (middle != NULL) {
        cout << "Middle of the Linked List:- " << middle->data << endl;
    }
    else {
        cout << "Linked List is empty:- " << endl;
    }
    Node* lastNode = myList.head;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }
    lastNode->next = myList.head->next;
    if (myList.hasCycle()) {
        cout << "Has cycle" << endl;
    }
    else {
        cout << "Don't have cycle" << endl;
    }
   */

    string input;
    cout << "Enter a word: ";
    cin >> input;

    if (isPalindrome(input)) {
        cout << "It's a palindrome!" << endl;
    }
    else {
        cout << "It's not a palindrome." << endl;
    }
    LinkedList l1, l2;
    l1.insertData(2);
    l1.insertData(5);
    l1.insertData(7);
    cout << "The First List is:- " ;
    l1.display();
    l2.insertData(3);
    l2.insertData(6);
    l2.insertData(9);
    cout << "The Second List is:- ";
    l2.display();
    LinkedList mergedList = mergeSortedLL(l1, l2);
    cout << "The merged list is :- ";
    mergedList.display();


    return 0;
}

