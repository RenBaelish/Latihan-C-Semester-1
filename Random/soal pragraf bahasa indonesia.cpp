#include <iostream>
#include <vector>
#include <string>

// Fungsi untuk memeriksa tanda baca di akhir kalimat
int cekTandaBaca(const std::string& kalimat) {
    // Pastikan kalimat tidak kosong terlebih dahulu
    if (kalimat.size() > 0) {
        // Ambil karakter terakhir dengan indeks
        char lastChar = kalimat[kalimat.size() - 1];
        
        // Jika karakter terakhir adalah titik, tanda tanya, atau tanda seru
        if (lastChar == '.' || lastChar == '?' || lastChar == '!') {
            return 1; // Benar
        }
    }
    return 0; // Salah
}

// Fungsi untuk memeriksa apakah kalimat efektif
int cekKalimatEfektif(int nomorKalimat) {
    // Untuk contoh sederhana, misalkan kalimat ke-2 dan ke-5 perlu disederhanakan
    if (nomorKalimat == 2 || nomorKalimat == 5) {
        return 0; // Tidak efektif
    }
    return 1; // Efektif
}

int main() {
    // Inisialisasi vektor secara tradisional
    std::vector<std::string> soal;
    soal.push_back("Bagi sebagian orang, melupakan mantan merupakan hal yang sangat sulit untuk dilakukan.");
    soal.push_back("Faktor utama yang menyebabkan terjadinya hal tersebut adalah kesepian.");
    soal.push_back("Setelah putus cinta, sosok yang biasa menemani, memperhatikan, dan setia mendengarkan setiap cerita telah hilang.");
    soal.push_back("Rasa kesepian itu yang memunculkan ingatan-ingatan tentang masa-masa indah bersama mantan.");
    soal.push_back("Alasan lain yang menyebabkan seseorang sulit melupakan mantan adalah banyaknya memori bersama mantan yang masih terekam dengan jelas.");
    soal.push_back("Bahkan, ketika tempat yang sering dikunjungi atau benda yang punya kenangan tersendiri terlihat di depan mata, semua cerita di balik hal-hal tersebut tiba-tiba muncul dan membuat mereka terkungkung di masa lalu.");
    soal.push_back("Banyaknya waktu yang dihabiskan bersama mantan juga menjadi salah satu alasan yang membuat beberapa orang sulit melupakan sosok yang pernah berarti dalam hidup mereka tersebut.");
    soal.push_back("Bahkan, ternyata, ada rentang waktu yang berkaitan dengan lamanya seseorang dalam melupakan mantan.");
    soal.push_back("Sebuah penelitian yang diterbitkan dalam Journal of Positive Psychology menunjukkan bahwa seseorang membutuhkan waktu sekitar tiga hingga enam bulan untuk melupakan masa lalunya.");
    soal.push_back("Jane Greer, seorang terapis pernikahan dan keluarga, mengatakan bahwa melupakan mantan dapat memakan waktu dari enam minggu, tiga bulan, hingga selamanya, tergantung pada seberapa intens hubungan tersebut dan seberapa besar seseorang menginvestasikan perasaannya di dalam hubungan tersebut.");
    soal.push_back("Dengan demikian, lama tidaknya seseorang dalam melupakan mantan berkaitan erat dengan besarnya rasa cinta orang tersebut terhadap mantannya.");

    int pilihan;
    int hasilTandaBaca, hasilEfektif;

    // Memeriksa setiap kalimat dalam soal
    for (size_t i = 0; i < soal.size(); ++i) {
        std::cout << "Kalimat " << i + 1 << ": " << soal[i] << std::endl;

        // Pertanyaan soal tanda baca
        std::cout << "Apakah tanda baca pada kalimat ini benar? (1 = Benar, 2 = Salah): ";
        std::cin >> pilihan;

        // Cek tanda baca
        hasilTandaBaca = cekTandaBaca(soal[i]);

        // Cek apakah jawaban pengguna benar atau salah
        if ((pilihan == 1 && hasilTandaBaca == 1) || (pilihan == 2 && hasilTandaBaca == 0)) {
            std::cout << "Jawaban Anda benar!" << std::endl;
        } else {
            std::cout << "Jawaban Anda salah!" << std::endl;
        }

        // Pertanyaan soal kalimat efektif (untuk beberapa kalimat saja)
        if (i == 1 || i == 4) { // Misal kalimat ke-2 dan ke-5 ada pertanyaan kalimat efektif
            std::cout << "Apakah kalimat ini sudah efektif? (1 = Efektif, 2 = Perlu disederhanakan): ";
            std::cin >> pilihan;

            // Cek efektivitas kalimat
            hasilEfektif = cekKalimatEfektif(i + 1);

            // Cek apakah jawaban pengguna benar atau salah
            if ((pilihan == 1 && hasilEfektif == 1) || (pilihan == 2 && hasilEfektif == 0)) {
                std::cout << "Jawaban Anda benar!" << std::endl;
            } else {
                std::cout << "Jawaban Anda salah!" << std::endl;
            }
        }

        std::cout << std::endl;
    }

    return 0;
}

