#include<iostream>
using namespace std;

int main(){
	
	int nilai[] = {1000, 2000, 3000};
	int pilihan;
	
	cout << "====Daftar Harga===="<<endl;
	
	for (int i = 0; i < 3; i++){
		cout << i + 1 << ". " <<nilai[i] <<"\n";
	}
	
	cout << "Masukkan Pilihan : ";
	cin>>pilihan;	
	
	if (pilihan >= 1 && pilihan <= 3){
		cout << "Maka anda harus membayar : "<< nilai[pilihan - 1]<<endl;
	} else {
		cout << "Pilihan tidak ada "<< "\n";
	}
	
	f
} 
