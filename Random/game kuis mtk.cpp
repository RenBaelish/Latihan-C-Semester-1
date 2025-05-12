#include <iostream>
#include <cstdlib>  // untuk rand() dan srand()
#include <ctime>    // untuk time()
using namespace std;

int generateQuestion() {
    int a = rand() % 10 + 1; // Angka acak pertama antara 1 dan 10
    int b = rand() % 10 + 1; // Angka acak kedua antara 1 dan 10
    int operation = rand() % 4; // Operasi acak: 0=+, 1=-, 2=*, 3=/
    int answer;

    switch (operation) {
        case 0:
            cout << "Berapakah " << a << " + " << b << "? ";
            answer = a + b;
            break;
        case 1:
            cout << "Berapakah " << a << " - " << b << "? ";
            answer = a - b;
            break;
        case 2:
            cout << "Berapakah " << a << " * " << b << "? ";
            answer = a * b;
            break;
        case 3:
            cout << "Berapakah " << a * b << " / " << b << "? ";
            answer = a; // Membalik operasi menjadi perkalian untuk pembagian
            break;
    }

    return answer;
}

void startQuiz() {
    int score = 0;
    int attempts = 5;
    int userAnswer;

    cout << "Selamat datang di Kuis Matematika!" << endl;
    cout << "Anda akan diberikan " << attempts << " soal untuk dijawab." << endl;

    for (int i = 0; i < attempts; i++) {
        int correctAnswer = generateQuestion();
        cin >> userAnswer;

        if (userAnswer == correctAnswer) {
            cout << "Benar!" << endl;
            score++;
        } else {
            cout << "Salah. Jawaban yang benar adalah " << correctAnswer << "." << endl;
        }
    }

    cout << "\nKuis selesai! Skor akhir Anda adalah: " << score << " dari " << attempts << endl;
}

int main() {
    srand(time(0)); // Seed untuk menghasilkan angka acak yang berbeda setiap kali program dijalankan
    char playAgain;

    do {
        startQuiz();
        cout << "Apakah Anda ingin mencoba lagi? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Terima kasih telah bermain!" << endl;
    return 0;
}

