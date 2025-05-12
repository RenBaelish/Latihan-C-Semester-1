#include<iostream>
using namespace std;

void panggil(){
	cout <<"I just got executed!"<<endl;
}

void perkalian(int angka1, int angka2){
	cout<<(angka1*angka2)<<endl;
}

void pembagian(int angka1, int angka2){
	cout<<(angka1/angka2)<<endl;
}

void jumlah(int angka1, int angka2){
	cout<<(angka1+angka2)<<endl;
}

void pengurangan(int angka1, int angka2){
	cout<<(angka1-angka2)<<endl;
}

string str1(){
	return "I just got executed!";
}

int main(){
	pembagian(4,4);
	perkalian(3,3);
	cout<<jumlah(2,3)<<endl;
	cout<<pengurangan(2,3)<<endl;
	
	
}
