#include<iostream>
#include<string>
using namespace std;

//pagi : 00 - 10
//siang : 11- 14
//sore : 15- 18
//malam : 19 - 23

int main(){
	int x;
	cout<<"Masukkan Jam Berapa Sekarang : ";
	cin>>x;
	
	if (x >= 0  && x  <= 10){
		cout<<"Maka Sekarang Pagi";
	}
	else if (x >= 11  && x  <= 14){
		cout<<"Maka Sekrang Siang";
	}
	else if (x >= 15  && x  <= 18){
		cout<<"Maka Sekarang Sore";
	}
	else if (x >= 19  && x  <= 24){
		cout<<"Maka Sekarang Sore";
	}
	else { 
		cout<<"Jam Cuman Sampai 24 tidak lebih";
	}
}
