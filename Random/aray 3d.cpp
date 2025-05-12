#include <iostream>
using namespace std;

int main() {
  string letters[2][2][2] = {
    {
      { "M", "A" },
      { "S", """\n" }
    },
    {
      { "A", "N" },
      { "I", "S" }
    }
  };

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        cout << letters[i][j][k] << "\n";
      }
    }
  }
  return 0;
}

