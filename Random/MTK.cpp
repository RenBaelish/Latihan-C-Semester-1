#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int wnum = 5;
	double dnum = 5.5;
	wnum +=95; //nambah 95 wnum nya
	cout<<wnum<<endl;
	
	cout<<pow(2, 6)<<endl; //2 pangkat 6
	cout<<sqrt(36)<<endl; //mencari  36 hasil dari berapa pangkat berapa
	cout<<round(4.3)<<endl; //pembulatan angkatan ke terdekat contoh 4.3 = 4, 4.7 = 5
	cout<<ceil(4.1)<<endl; //membulatkan angka ke tertinggi misalkan 4.1 = 5 
	cout<<floor(4.8)<<endl; //kebalikan dari ceil angkatnya dibulatkan ke terbawah contoh 4.1 = 4
	cout<<fmax(3, 2)<<endl; //angka tertinggi di dalam kurung
	cout<<fmin(3, 2)<<endl; //angka terendah di dalam kurung
}
