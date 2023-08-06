
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include <string>

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
*/
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


int main()
{
    /*
    * string str = "amittomar";
    reverseString(str);
    cout << str;
    */
    
    int n = 6;
    printingPattern(n);
    return 0;
}

