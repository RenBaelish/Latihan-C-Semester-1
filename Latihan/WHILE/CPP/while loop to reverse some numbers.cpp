#include <iostream>
using namespace std;

int main() {
  // A variable with some specific numbers
  int numbers = 12345;

  // A variable to store the reversed number
  int revNumbers = 0;

  // Reverse and reorder the numbers
  while (numbers) {
    // Get the last number of 'numbers' and add it to 'revNumbers'
    revNumbers = revNumbers * 10 + numbers % 10;
    // Remove the last number of 'numbers'
    numbers /= 10;
  }

  cout << "Reversed numbers: " << revNumbers << "\n";

}

