#include<iostream>
using namespace std;

int main(){
	int pil;
	string jkel;
	
	cout<<"Pilih salah satu : "<<endl;
	cout<<"1. Laki-laki\n2. Perempuan"<<endl;
	cout<<"Pilihan : ";
	cin>>pil;
	
	switch(pil){
		case  1 :
			jkel = "Laki-laki";
			break;
		case 2 : 
			jkel = "Perempuan";
			break;
		default:
			jkel = "Pilihan salah";
	}
	cout<<"Jenis kelamin saya adalah "<<jkel;
}
