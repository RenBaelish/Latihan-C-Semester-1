#include<iostream>
using namespace std;

int main(){
	string myString = "Rafi";
  cout << "Original string: " << myString << "\n";
  
  cout << "First character: " << myString.at(0) << "\n";
  cout << "Second character: " << myString.at(1) << "\n";
  cout << "Last character: " << myString.at(myString.length() - 1) << "\n";
  
  myString.at(2) = 'p';
  cout << "Changed string: " << myString;
  return 0;
}

