#include <iostream>
#include <string>

using namespace std;

int main() {
    string questions[] = {
        "1. Apakah kalimat 'Setiap murid di kelas itu belajar dengan giat dan bersungguh-sungguh.' sudah efektif dalam kehematan kata?",
        "2. Apakah kalimat 'Kegiatan yang diadakan oleh sekolah pada hari Senin dan Selasa akan sangat bermanfaat bagi siswa.' memiliki kesepadanan struktur?",
        "3. Apakah kalimat 'Dia pergi ke taman, berenang di kolam, dan bermain layang-layang.' memiliki kesejajaran bentuk?",
        "4. Apakah kalimat 'Meski hujan deras, acara pernikahan tetap berlangsung dengan meriah.' memiliki ketegasan makna?",
        "5. Apakah kalimat 'Rina dan teman-temannya pergi ke bioskop setelah mereka menyelesaikan tugas.' logis?",
        "6. Apakah kalimat 'Dia pergi ke toko, membeli buku dan juga membeli pena.' efektif dalam penggunaan kata?",
        "7. Apakah kalimat 'Ketika malam tiba, bintang-bintang mulai muncul dan bulan bersinar terang di langit.' memiliki kesepadanan struktur?",
        "8. Apakah kalimat 'Dengan belajar secara konsisten, hasil ujian akan meningkat dan dapat meraih prestasi.' logis?",
        "9. Apakah kalimat 'Kucing peliharaanku sangat lucu dan suka bermain, tetapi dia juga suka tidur.' hemat dalam penggunaan kata?",
        "10. Apakah kalimat 'Dalam rapat tersebut, dia menyampaikan pendapatnya, sementara peserta lain mendengarkan.' efektif dalam kejelasan?",
        "11. Apakah kalimat 'Saya tidak mengerti mengapa dia tidak datang ke pertemuan itu, padahal saya sudah mengingatkannya.' jelas dan tegas?",
        "12. Apakah kalimat 'Setelah menonton film itu, saya merasa senang, juga sangat terhibur.' memiliki kesejajaran bentuk?",
        "13. Apakah kalimat 'Ketika dia datang, saya sudah pergi, dan juga teman-teman saya sudah berangkat.' logis?",
        "14. Apakah kalimat 'Kegiatan ini akan diadakan pada bulan Maret dan setiap orang diundang untuk berpartisipasi.' jelas dan efektif?",
        "15. Apakah kalimat 'Sebelum memutuskan, sebaiknya kita mempertimbangkan semua aspek yang ada.' mengandung ketegasan makna?",
        "16. Apakah kalimat 'Setiap sore, dia berolahraga di taman, dan di malam hari, dia membaca buku.' efektif dalam kehematan kata?",
        "17. Apakah kalimat 'Pelatihan ini bertujuan untuk meningkatkan kemampuan dan juga menambah pengetahuan.' memiliki kesejajaran?",
        "18. Apakah kalimat 'Mereka merencanakan perjalanan ke Bali, sedangkan saya memilih untuk tinggal di rumah.' jelas dan logis?",
        "19. Apakah kalimat 'Meskipun hujan, mereka tetap pergi, dan tidak ada yang menyesal dengan keputusan itu.' hemat dalam penggunaan kata?",
        "20. Apakah kalimat 'Anak-anak bermain di taman, sambil mereka tertawa dan berlari-lari.' memiliki ketegasan makna?"
    };
    
    bool answers[] = {
        false, true, true, true, true, false, true, true, false, true,
        true, false, true, true, true, true, false, true, true, false
    }; // jawaban yang benar (True/False)

    // Penjelasan untuk setiap soal
    string explanations[] = {
        "Kalimat ini tidak hemat karena ada pengulangan kata 'belajar' dan 'bersungguh-sungguh'. Cukup katakan 'Setiap murid di kelas itu belajar dengan giat.'",
        "Kalimat ini memiliki kesepadanan struktur karena dua bagian kalimat saling berkaitan dengan jelas.",
        "Kalimat ini memiliki kesejajaran karena semua aktivitas menggunakan pola yang sama.",
        "Kalimat ini tegas karena menunjukkan bahwa meskipun ada halangan, acara tetap berlangsung.",
        "Kalimat ini logis karena menyatakan urutan waktu yang jelas.",
        "Kalimat ini tidak efektif karena ada pengulangan dalam tindakan membeli. Cukup katakan 'Dia pergi ke toko dan membeli buku serta pena.'",
        "Kalimat ini sepadan karena menggambarkan dua aktivitas yang terjadi bersamaan.",
        "Kalimat ini logis karena menghubungkan hasil dengan proses belajar.",
        "Kalimat ini tidak hemat karena ada pengulangan pada deskripsi sifat kucing. Cukup katakan 'Kucing peliharaanku sangat lucu dan suka bermain.'",
        "Kalimat ini efektif karena menyampaikan dua informasi yang saling mendukung.",
        "Kalimat ini jelas karena memberikan alasan yang kuat tentang ketidakhadiran.",
        "Kalimat ini tidak seimbang karena menggunakan kata 'juga' yang membuatnya tidak konsisten.",
        "Kalimat ini logis karena menyatakan dua keadaan yang berurutan.",
        "Kalimat ini jelas dan efektif karena langsung menyampaikan informasi dengan ketegasan.",
        "Kalimat ini tegas karena menunjukkan urgensi untuk mempertimbangkan semua aspek sebelum mengambil keputusan.",
        "Kalimat ini efektif karena menyampaikan dua aktivitas dengan jelas dan tidak ada pengulangan.",
        "Kalimat ini tidak sepadan karena penggunaan 'juga' yang tidak perlu.",
        "Kalimat ini jelas dan logis karena menyatakan dua pilihan yang berbeda dengan jelas.",
        "Kalimat ini tidak hemat karena ada pengulangan frasa 'mereka' dan 'tidak ada yang menyesal'.",
        "Kalimat ini tidak tegas karena frasa 'sambil mereka' membuatnya menjadi ambigu."
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

