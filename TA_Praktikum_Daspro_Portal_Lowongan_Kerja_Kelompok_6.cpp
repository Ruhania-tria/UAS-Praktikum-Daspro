   #include <iostream>
#include <limits>
using namespace std;

// Struct untuk menyimpan data pekerjaan
struct Pekerjaan {
    string namaPekerjaan;
    string lokasi;
    string kriteria;
    string nomor;
};

// Array untuk menyimpan pekerjaan (maksimal 50)
Pekerjaan daftarPekerjaan[50];
int jumlahPekerjaan = 10;

// Fungsi untuk menginisialisasi pekerjaan awal
void inisialisasiPekerjaan() {
    daftarPekerjaan[0] = {"Programmer", "Palu", "Teknologi","123456"};
    daftarPekerjaan[1] = {"UI/UX Desainer", "Pasangkayu", "Teknologi", "405912"};
    daftarPekerjaan[2] = {"Tukang Bangunan", "Palu Barat", "Jasa", "770321"};
    daftarPekerjaan[3] = {"Guru Matematika", "Banggai", "Pendidikan", "918204"};
    daftarPekerjaan[4] = {"Dokter Umum", "Morowali", "Kesehatan", "284917"};
    daftarPekerjaan[5] = {"Data Scientist""Jakarta", "Teknologi", "650238"};
    daftarPekerjaan[6] = {"Peternak Ayam", "Bambaira", "Pertanian", "731904"};
    daftarPekerjaan[7] = {"Montir Mobil", "Talise", "Jasa", "509672"};
    daftarPekerjaan[8] = {"Pengajar Bahasa Inggris", "Sigi", "Pendidikan","842316"};
    daftarPekerjaan[9] = {"Perawat", "Poso", "Kesehatan", "099776"};
}

// Fungsi untuk menampilkan semua pekerjaan
void tampilkanPekerjaan() {
    cout << "\nDaftar Lowongan pekerjaan yang tersedia:\n";
    for (int i = 0; i < jumlahPekerjaan; i++) {
        cout << i + 1 << ". Nama: " << daftarPekerjaan[i].namaPekerjaan
             << ", Lokasi: " << daftarPekerjaan[i].lokasi
             << ", Kriteria: " << daftarPekerjaan[i].kriteria
             << ", Nomor: " << daftarPekerjaan[i].nomor << endl;
    }
    string kerja;
    char lamaran;
    cout << "Kirim lamaran pekerjaan(Y/N):"; 
    cin>>lamaran;
      if (lamaran=='Y'){
        cout<< "Anda ingin melamar pekerjaan apa:";
       cin>>kerja;
        cout<<"Lamaran pekerjaan anda berhasil dikirimkan"<<endl;
          cout << "\nSilakan hubungi lokasi untuk informasi lebih lanjut!\n";
      }
}

// Fungsi untuk mencari pekerjaan berdasarkan kriteria
void cariloker() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string kriteria, kerja;
    char lamaran;
    cout << "Masukkan kriteria pekerjaan (Teknologi, Pertanian, Jasa, Pendidikan, Kesehatan): ";
    getline(cin, kriteria);

    cout << "\nRekomendasi Pekerjaan untuk Kriteria '" << kriteria << "':\n";

    bool ditemukan = false;

    for (int i = 0; i < jumlahPekerjaan; i++) {
        if (daftarPekerjaan[i].kriteria == kriteria) {
            cout << "- Nama: " << daftarPekerjaan[i].namaPekerjaan
                 << ", Lokasi: " << daftarPekerjaan[i].lokasi
                 << ", Nomor: " << daftarPekerjaan[i].nomor << endl;
            ditemukan = true;
        }
    }{cout << "Kirim lamaran pekerjaan(Y/N):"; 
    cin>>lamaran;
      if (lamaran=='Y'){
        cout<< "Anda ingin melamar pekerjaan apa:";
       cin>>kerja;
        cout<<"Lamaran pekerjaan anda berhasil dikirimkan"<<endl;
      }
    }

    if (!ditemukan) {
        cout << "Tidak ada pekerjaan yang cocok dengan kriteria tersebut.\n";
    } else {
        cout << "\nSilakan hubungi lokasi untuk informasi lebih lanjut!\n";
    }
}


// Fungsi untuk menambahkan pekerjaan bari
void tambahPekerjaan() {
    if (jumlahPekerjaan >= 50) {
        cout << "Data penuh! Tidak bisa menambahkan lowongan pekerjaan.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Pekerjaan baru;
    cout << "\n=== Tambah Lowongan Pekerjaan Baru ===\n";

    cout << "Masukkan nama pekerjaan: ";
    getline(cin, baru.namaPekerjaan);

    cout << "Masukkan lokasi pekerjaan: ";
    getline(cin, baru.lokasi);

    cout << "Masukkan kriteria pekerjaan: ";
    getline(cin, baru.kriteria);

    cout << "Masukkan nomor terkait (6 digit): ";
    getline(cin, baru.nomor);

    daftarPekerjaan[jumlahPekerjaan] = baru;
    jumlahPekerjaan++;

    cout << "\nPekerjaan berhasil ditambahkan!\n";
}

int main() {
    inisialisasiPekerjaan();

    int pilihan;

    while (true) {
        cout << "\n=== Portal Lowongan Kerja ===\n";
        cout << "1. Tampilkan daftar lowongan pekerjaan yang tersedia\n";
        cout << "2. Cari lowongan kerja\n";
        cout << "3. Pasang lowongan Kerja\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu (1-4): ";

        // Input pilihan dengan validasi
        while (true) {
            cin >> pilihan;
            if (cin.fail() || pilihan < 1 || pilihan > 4) {
                cout << "Input tidak valid! Masukkan angka 1-4: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else break;
        }

        switch (pilihan) {
            case 1: tampilkanPekerjaan(); break;
            case 2: cariloker(); break;
            case 3: tambahPekerjaan(); break;
            case 4:
                cout << "Terima kasih telah menggunakan platform ini!\n";
                return 0;
        }
    }

    return 0;
}
