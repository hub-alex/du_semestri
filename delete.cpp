#include <iostream>
using namespace std;

int main() {
    int num = 123;
    cout << "Without setting width:\n";
    cout << num << "\n"; // Default output without width set.

    cout << "With width set to 10:\n";
    cout.width(10); // Sets the field width to 10 for the next output operation.
    cout << num << "\n"; // Output will be padded to meet the minimum width.

    // Setting width and left alignment
    cout << "With width set to 10 and left alignment:\n";
    cout.setf(ios::left); // Sets alignment to left.
    cout.width(10); // Sets the field width to 10 for the next output operation.
    cout << num << "\n"; // Output will be padded on the right.

    return 0;
}