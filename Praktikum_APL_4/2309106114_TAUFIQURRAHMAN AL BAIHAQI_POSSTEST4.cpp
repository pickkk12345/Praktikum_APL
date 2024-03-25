#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX_SARUNG = 100;
const int MAX_VARIAN = 10;

struct Sarung {
   string merk;
   string varian[MAX_VARIAN]; // <-- ini adalah nested struct
   int jumlahVarian;
};

vector<Sarung> daftarSarung; // <-- ini adalah array of struct 

string nama = "opick";
string nim = "114";
int trylogin = 0;
int limitlogin = 3;

void tampilkanSarung() {
   if (daftarSarung.empty()) {
       cout << "Tidak ada sarung yang tersedia." << endl;
       return;
   }

   for (const auto& sarung : daftarSarung) {
       cout << "Sarung yang tersedia dari merk " << sarung.merk << " : " << endl;
       for (int j = 0; j < sarung.jumlahVarian; j++) {
           cout << " - " << sarung.varian[j] << endl;
       }
       cout << endl;
   }
}

void tambahSarung() {
   string merk, varian;
   cout << "Masukkan merk sarung baru : ";
   cin >> merk;

   Sarung sarungBaru;
   sarungBaru.merk = merk;
   sarungBaru.jumlahVarian = 0;

   cout << "Masukkan varian sarung (ketik 'selesai' untuk berhenti): " << endl;
   cin.ignore();
   while (true) {
       getline(cin, varian);
       if (varian == "selesai") {
           break;
       }
       if (sarungBaru.jumlahVarian < MAX_VARIAN) {
           sarungBaru.varian[sarungBaru.jumlahVarian++] = varian;
       } else {
           cout << "Jumlah varian sarung sudah mencapai batas maksimum" << endl;
           break;
       }
   }

   if (sarungBaru.jumlahVarian > 0) {
       daftarSarung.push_back(sarungBaru);
   } else {
       cout << "Tidak ada varian sarung yang ditambahkan." << endl;
   }
}

void updateSarung() {
    string merk, varian_lama, varian_baru;
    cout << "Pilih merk sarung yang ingin diupdate : ";
    cin >> merk;

    bool found = false;
    for (auto& sarung : daftarSarung) {
        if (sarung.merk == merk) {
            cout << "Masukkan varian sarung yang ingin diupdate : ";
            cin.ignore();
            getline(cin, varian_lama);

            bool varian_ditemukan = false;
            for (int i = 0; i < sarung.jumlahVarian; i++) {
                if (sarung.varian[i] == varian_lama) {
                    cout << "Masukkan varian sarung yang baru : ";
                    getline(cin, varian_baru);
                    sarung.varian[i] = varian_baru;
                    varian_ditemukan = true;
                    break;
                }
            }

            if (!varian_ditemukan) {
                cout << "Varian sarung tidak ditemukan." << endl;
            }

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Merk sarung tidak ditemukan." << endl;
    }
}

void hapusSarung() {
   string merk;
   cout << "Masukkan merk sarung yang ingin dihapus : ";
   cin >> merk;

   for (auto it = daftarSarung.begin(); it != daftarSarung.end(); ++it) {
       if (it->merk == merk) {
           daftarSarung.erase(it);
           cout << "Sarung dengan merk " << merk << " berhasil dihapus." << endl;
           return;
       }
   }

   cout << "Merk sarung tidak ditemukan." << endl;
}

int login(int trylogin = 0) {
   if (trylogin == limitlogin) {
       cout << "Login gagal, silahkan coba lagi nanti." << endl;
       return 0;
   }

   string inputNama, inputNim;
   cout << "Masukkan nama anda : ";
   cin >> inputNama;
   cout << "Masukkan NIM anda : ";
   cin >> inputNim;

   if (inputNama == nama && inputNim == nim) {
       cout << "Login berhasil" << endl;
       string masukan_pilihan;
       while (true) {
           cout << "1. Tampilkan semua jenis sarung" << endl;
           cout << "2. Tambahkan jenis varian sarung" << endl;
           cout << "3. Update jenis varian sarung" << endl;
           cout << "4. Hapus jenis varian sarung" << endl;
           cout << "5. Logout" << endl;
           cout << "Masukkan pilihan anda : ";
           cin >> masukan_pilihan;

           if (masukan_pilihan == "1") {
               tampilkanSarung();
           } else if (masukan_pilihan == "2") {
               tambahSarung();
           } else if (masukan_pilihan == "3") {
               updateSarung();
           } else if (masukan_pilihan == "4") {
               hapusSarung();
           } else if (masukan_pilihan == "5") {
               cout << "Anda telah logout" << endl;
               break;
           } else {
               cout << "Pilihan anda tidak tersedia" << endl;
           }
       }
       return 1;
   } else {
       cout << "Login gagal" << endl;
       return login(trylogin + 1);
   }
}

int main() {
   cout << "Selamat datang di toko sarung" << endl;
   cout << "Silahkan login" << endl;
   login();
   return 0;
}