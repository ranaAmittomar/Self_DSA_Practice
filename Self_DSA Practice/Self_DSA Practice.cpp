
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
*/
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


int main()
{
    /*
    * string str = "amittomar";
    reverseString(str);
    cout << str;
    */
    /*
    * int n = 6;
    printingPattern(n);
    */
    /*
    int n;
    cout << "Enter the value to print the pattern:- ";
    cin >> n;
    printingPattern2(n);
    */
    int n;
    cin >> n;
    printingPattern3(n);

    return 0;
}

