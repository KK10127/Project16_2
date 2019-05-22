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
 *
 *
 */
#include <iostream>
#include <cmath>
using namespace std;

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
    cout << "Welcome to the demo of project 2!" << endl;

    int num;

    cout << "Enter a perfect square: ";
    cin >> num;
    try {
        cout << "\tROOT IS:" << getRoot(num) << endl;
    } catch(NotAPerfectSquareException e) {
        e.printMessage();
    }
    cout << "Enter a NOT SO perfect square: ";
    cin >> num;
    try {
        cout << "\tROOT IS:" << getRoot(num) << endl;
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