/*
 * CHAPTER 16, PROJECT 2
 * CS 151
 * Tu 5:30-9:20 with Porto
 * Programmer: Jay Montoya
 *
 * PROBLEM STATEMENT:
 *     Write a function that accepts an integer parameter and returns its intege r square root
 *     The function should throw an exception if it is passed an integer that is not a perfect square. Demonstrate the
 *     function with a suitable driver program
 *
 * ALGORITHM:
 *      1. Prompt user for a number that is a perfect square.
 *      2. Try to get the root by calling the function.
 *      3. Catch the exception when thrown.
 *      4. Promp the user for a non-perfect square.
 *      5. Try to get the root by calling the function.
 *      6. Catch the exception when thrown.
 *
 *
 */
#include <iostream>
#include <cmath>
using namespace std;

// function prototypes
int getRoot(int num);

class NotAPerfectSquareException {
private:
    string x;
public:
    NotAPerfectSquareException(string msg);
    void printMessage();
};

NotAPerfectSquareException::NotAPerfectSquareException(string msg) {
    x = msg;
}
void NotAPerfectSquareException::printMessage() {
    cout << "\t" << x;
}


int main() {
    // greeting
    cout << "Welcome to the demo of project 2!" << endl;

    // number to enter
    int num;

    cout << "Enter a perfect square: ";
    cin >> num;
    // try to get the Root
    try {
        cout << "\tROOT IS:" << getRoot(num) << endl;
    // catch the exception for a not so perfect square
    } catch(NotAPerfectSquareException e) {
        e.printMessage();
    }

    // prompt user for a not so perfect square
    cout << "Enter a NOT SO perfect square: ";
    cin >> num;
    // try to get the Root
    try {
        cout << "\tROOT IS:" << getRoot(num) << endl;
    // catch the exception for a not so perfect square
    } catch(NotAPerfectSquareException e) {
        e.printMessage();
    }

    return 0;
}

int getRoot(int num) {
    // Find floating point value of
    // square root of x.
    long double sr = sqrt(num);

    // If square root is an integer
    if ((sr - floor(sr)) == 0) {
        return (int) sr;
    } else {
        throw NotAPerfectSquareException("Not a perfect square!");
    }
}