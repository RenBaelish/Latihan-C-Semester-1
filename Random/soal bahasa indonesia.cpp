#include <iostream>
#include <string>

using namespace std;

int main() {
    string questions[] = {
        "1. Apakah kalimat 'Ibu pergi ke pasar untuk membeli buah dan dia juga membeli sayuran.' sudah hemat kata?",
        "2. Apakah kalimat 'Saya sudah belajar selama dua jam dan besok saya akan belajar.' memiliki kesepadanan struktur?",
        "3. Apakah kalimat 'Andi suka berenang, bersepeda, dan dia juga suka untuk membaca buku.' memiliki kesejajaran bentuk?",
        "4. Apakah kalimat 'Dia tahu bahwa mereka akan pergi dan dia berharap mereka akan kembali.' memiliki ketegasan makna?",
        "5. Apakah kalimat 'Ketika hujan datang, maka air akan tumpah.' logis?",
        "6. Apakah kalimat 'Ali menutup pintu, dia juga mengunci pintu.' efektif dalam kehematan kata?",
        "7. Apakah kalimat 'Ibu sedang memasak di dapur, sementara ayah menonton televisi di ruang tamu.' memiliki kesepadanan struktur?",
        "8. Apakah kalimat 'Mereka belajar di perpustakaan, tetapi dia bermain di luar.' memiliki kelogisan?",
        "9. Apakah kalimat 'Budi pergi ke sekolah, lalu dia membeli buku dan dia membaca buku di perpustakaan.' sudah hemat dalam penggunaan kata?",
        "10. Apakah kalimat 'Dia mendengarkan musik sambil dia memasak makan siang.' memiliki kesejajaran bentuk?",
        "11. Apakah kalimat 'Kucing itu tidur di atas sofa.' sudah jelas dan padat?",
        "12. Apakah kalimat 'Dia suka sekali bermain bola dan juga dia sangat suka bersepeda.' memiliki kesejajaran bentuk?",
        "13. Apakah kalimat 'Pagi ini hujan lebat dan sore ini juga hujan.' logis?",
        "14. Apakah kalimat 'Makan siang sudah siap, silakan kamu makan.' tegas dan jelas?",
        "15. Apakah kalimat 'Guru mengajarkan matematika, dan pelajaran lainnya.' sudah efektif?",
        "16. Apakah kalimat 'Mobil itu sangat cepat, lebih cepat daripada sepeda motor.' memiliki ketegasan makna?",
        "17. Apakah kalimat 'Dia belajar untuk ujian sambil mendengarkan musik.' sudah konsisten?",
        "18. Apakah kalimat 'Sore itu saya pergi ke taman dan juga saya bertemu teman.' efektif dalam penggunaan kata?",
        "19. Apakah kalimat 'Rina sangat pandai bermain piano dan dia juga sangat suka bernyanyi.' memiliki kesepadanan struktur?",
        "20. Apakah kalimat 'Ketika matahari terbenam, langit berwarna oranye.' logis?"
    };
    
    bool answers[] = {
        false, true, false, true, true, false, true, true, false, false,
        true, false, true, true, false, true, true, false, false, true
    }; // jawaban yang benar (True/False)

    // Penjelasan untuk setiap soal
    string explanations[] = {
        "Kalimat tersebut tidak hemat karena ada pengulangan. Cukup dengan mengatakan 'Ibu pergi ke pasar untuk membeli buah dan sayuran.'",
        "Kalimat ini memiliki kesepadanan struktur karena bagian awal dan akhir kalimat memiliki hubungan yang jelas dan seimbang.",
        "Kalimat ini tidak sejajar karena bentuk pertama menggunakan kata kerja (berenang, bersepeda), tapi bentuk ketiga berubah menjadi 'untuk membaca', yang tidak konsisten.",
        "Kalimat ini tegas karena setiap bagian mendukung makna utama tanpa mengulang atau menyimpang dari inti pesan.",
        "Kalimat tersebut logis karena ada hubungan sebab-akibat yang jelas: hujan menyebabkan air tumpah.",
        "Kalimat ini tidak hemat, karena ada pengulangan. Sebaiknya cukup mengatakan 'Ali menutup dan mengunci pintu.'",
        "Kalimat ini sepadan karena aktivitas dua subjek (ibu dan ayah) diceritakan dengan struktur yang seimbang.",
        "Kalimat ini logis karena ada hubungan yang masuk akal antara kedua klausa (belajar dan bermain).",
        "Kalimat ini tidak hemat, karena ada pengulangan frasa 'dia membeli buku' dan 'dia membaca buku'. Sebaiknya dihindari pengulangan.",
        "Kalimat ini tidak sejajar, karena menggunakan 'mendengarkan' dan 'memasak', yang seharusnya sama bentuknya.",
        "Kalimat ini jelas dan padat karena langsung menyatakan keadaan kucing tanpa pengulangan.",
        "Kalimat ini tidak seimbang karena penggunaan 'suka' berulang tanpa kejelasan.",
        "Kalimat ini tidak logis karena tidak perlu menyebutkan hujan dua kali.",
        "Kalimat ini jelas dan tegas karena langsung menyampaikan informasi.",
        "Kalimat ini tidak efektif karena ada pengulangan. Cukup katakan 'Guru mengajarkan matematika dan pelajaran lainnya.'",
        "Kalimat ini tegas karena membandingkan mobil dan sepeda motor secara langsung.",
        "Kalimat ini konsisten karena menggambarkan dua aktivitas yang dilakukan bersamaan.",
        "Kalimat ini tidak efektif karena ada pengulangan. Cukup katakan 'Sore itu saya pergi ke taman dan bertemu teman.'",
        "Kalimat ini tidak sepadan karena terdapat pengulangan kata 'sangat'.",
        "Kalimat ini logis karena menggambarkan kejadian yang bisa terjadi secara alami."
    };

    bool userAnswer;
    int score = 0;
    
    cout << "Jawablah pertanyaan berikut dengan True (1) atau False (0):\n\n";

    for (int i = 0; i < 20; i++) {
        cout << questions[i] << " (1/0): ";
        cin >> userAnswer;
        
        if (userAnswer == answers[i]) {
            cout << "Jawaban Anda Benar!\n";
            score++;
        } else {
            cout << "Jawaban Anda Salah!\n";
        }
        
        // Tampilkan penjelasan setiap soal setelah dijawab
        cout << "Penjelasan: " << explanations[i] << "\n" << endl;
    }
    
    cout << "Skor akhir Anda adalah: " << score << " dari 20." << endl;

    return 0;
}

