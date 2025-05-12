#include<iostream>
using namespace std;
#include<string>

int main(){
	string username, password, valid_username = "rapii", valid_password = "nama";
	
	cout<<"Masukkan Username : ";
	getline(cin, username);
	cout<<"Masukkan Password : ";
	getline(cin, password);
	
	if (username==valid_username && password==valid_password ){
		cout<<"Berhasil Login\n"; 
		} 
	else {
		cout<<"Gagal Login";
	}
}
