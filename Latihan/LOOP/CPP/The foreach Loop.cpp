#include <iostream>
using namespace std;

int main() {
  // Create an array of integers
  int myNumbers[5] = {10, 20, 30, 40, 50};
  
  // Loop through integers
  for (int i : myNumbers) {
    cout << i << "\n";
  }
}

