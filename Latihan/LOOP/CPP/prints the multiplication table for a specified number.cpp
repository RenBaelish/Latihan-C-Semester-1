#include <iostream>
using namespace std;

int main() {
  int number = 2;
  int i;

  // Print the multiplication table for the number 2
  for (i = 1; i <= 10; i++) {
    cout << number << " x " << i << " = " << number * i << "\n";
  }

  return 0;
}

