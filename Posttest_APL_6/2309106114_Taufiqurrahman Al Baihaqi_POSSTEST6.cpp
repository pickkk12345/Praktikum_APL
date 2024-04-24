#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Untuk menggunakan fungsi std::sort
#include <cctype> // Untuk menggunakan fungsi std::tolower
using namespace std;

const int MAX_SARUNG = 100;
const int MAX_VARIAN = 10;

struct Sarung {
    string merk;
    string varian[MAX_VARIAN];
    int jumlahVarian;
    int harga[MAX_VARIAN];
};

vector<Sarung*> daftarSarung;

string nama = "opick";
string nim = "114";
int trylogin = 0;
int limitlogin = 3;

// Fungsi login
bool login() {
    if (trylogin == limitlogin) {
        cout << "Login gagal, silahkan coba lagi nanti." << endl;
        return false;
    }

    string inputNama, inputNim;
    cout << "Masukkan nama anda : ";
    cin >> inputNama;
    cout << "Masukkan NIM anda : ";
    cin >> inputNim;

    if (inputNama == nama && inputNim == nim) {
        cout << "Login berhasil" << endl;
        return true;
    } else {
        cout << "Login gagal" << endl;
        trylogin++;
        return login(); // Rekursif untuk mencoba login lagi
    }
}

// Fungsi untuk membandingkan dua objek Sarung berdasarkan merk secara ascending
bool compareSarungAscending(const Sarung* a, const Sarung* b) {
    string merkA = a->merk;
    string merkB = b->merk;
    transform(merkA.begin(), merkA.end(), merkA.begin(), ::tolower);
    transform(merkB.begin(), merkB.end(), merkB.begin(), ::tolower);
    return merkA < merkB; // Membandingkan secara leksikografis
}

// Fungsi untuk membandingkan dua objek Sarung berdasarkan merk secara descending
bool compareSarungDescending(const Sarung* a, const Sarung* b) {
    string merkA = a->merk;
    string merkB = b->merk;
    transform(merkA.begin(), merkA.end(), merkA.begin(), ::tolower);
    transform(merkB.begin(), merkB.end(), merkB.begin(), ::tolower);
    return merkA > merkB; // Membandingkan secara leksikografis
}

vector<Sarung*> cariSarungAscending(const string& keyword) {
    vector<Sarung*> hasilPencarian;
    for (const auto& sarungPtr : daftarSarung) {
        if (sarungPtr->merk.find(keyword) != string::npos) {
            hasilPencarian.push_back(sarungPtr);
        }
    }

    // Urutkan hasil pencarian berdasarkan merk sarung secara ascending
    sort(hasilPencarian.begin(), hasilPencarian.end(), [](const Sarung* a, const Sarung* b) {
        return a->merk < b->merk;
    });

    // Urutkan varian sarung di dalam setiap merek secara ascending
    for (auto& sarungPtr : hasilPencarian) {
        sort(sarungPtr->varian, sarungPtr->varian + sarungPtr->jumlahVarian);
    }

    return hasilPencarian;
}

vector<Sarung*> cariSarungDescending(const string& keyword) {
    vector<Sarung*> hasilPencarian;
    for (const auto& sarungPtr : daftarSarung) {
        if (sarungPtr->merk.find(keyword) != string::npos) {
            hasilPencarian.push_back(sarungPtr);
        }
    }

    // Urutkan hasil pencarian berdasarkan merk sarung secara descending
    sort(hasilPencarian.begin(), hasilPencarian.end(), [](const Sarung* a, const Sarung* b) {
        return a->merk > b->merk;
    });

    // Urutkan varian sarung di dalam setiap merek secara descending
    for (auto& sarungPtr : hasilPencarian) {
        sort(sarungPtr->varian, sarungPtr->varian + sarungPtr->jumlahVarian, greater<string>());
    }

    return hasilPencarian;
}

// Bubble Sort
void bubbleSortDescending(vector<string>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortAscending(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortAscending(arr, low, pi - 1);
        quickSortAscending(arr, pi + 1, high);
    }
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void tampilkanSarung(const vector<Sarung*>& dataSarung) {
    if (dataSarung.empty()) {
        cout << "Tidak ada sarung yang tersedia." << endl;
        return;
    }

    for (const auto& sarungPtr : dataSarung) {
        Sarung* sarung = sarungPtr; // Dereference pointer
        cout << "Sarung dari merk " << sarung->merk << " : " << endl;
        for (int j = 0; j < sarung->jumlahVarian; j++) {
            cout << " - " << sarung->varian[j] << " - Harga: " << "Rp : " << sarung->harga[j] << endl;
        }
        cout << endl;
    }
}

void tambahSarung() {
    string merk, varian;
    int harga;
    cout << "Masukkan merk sarung baru : ";
    cin >> merk;

    Sarung* sarungBaru = new Sarung; // Alokasi dinamis dengan pointer
    sarungBaru->merk = merk;
    sarungBaru->jumlahVarian = 0;

    cout << "Masukkan varian sarung (ketik 'selesai' untuk berhenti): " << endl;
    cin.ignore(); // Membersihkan newline dari buffer cin sebelum menggunakan getline
    while (sarungBaru->jumlahVarian < MAX_VARIAN) {
        cout << "Masukkan varian: ";
        getline(cin, varian);
        if (varian == "selesai") {
            break;
        }
        sarungBaru->varian[sarungBaru->jumlahVarian] = varian;
        
        // Memeriksa input harga apakah merupakan angka atau bukan
        cout << "Masukkan harga untuk varian " << varian << ": ";
        while (!(cin >> harga)) {
            cin.clear(); // Mengembalikan status cin ke normal
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Menghapus input yang tidak valid
            cout << "Harga harus berupa angka. Silakan masukkan kembali: ";
        }
        sarungBaru->harga[sarungBaru->jumlahVarian] = harga;
        sarungBaru->jumlahVarian++;
        cin.ignore(); // Membersihkan newline dari buffer cin setelah menggunakan cin untuk harga
    }

    if (sarungBaru->jumlahVarian > 0) {
        daftarSarung.push_back(sarungBaru);
    } else {
        cout << "Tidak ada varian sarung yang ditambahkan." << endl;
        delete sarungBaru; // Hapus alokasi dinamis jika tidak ada varian
    }
}


void updateSarung(Sarung* sarung) { // Parameter address-of
    string varian_lama, varian_baru;
    cout << "Masukkan varian sarung yang ingin diupdate : ";
    cin.ignore();
    getline(cin, varian_lama);

    bool varian_ditemukan = false;
    for (int i = 0; i < sarung->jumlahVarian; i++) {
        if (sarung->varian[i] == varian_lama) {
            cout << "Masukkan varian sarung yang baru : ";
            getline(cin, varian_baru);
            sarung->varian[i] = varian_baru;
            cout << "Masukkan harga untuk varian " << varian_baru << ": ";
            cin >> sarung->harga[i];
            varian_ditemukan = true;
            break;
        }
    }

    if (!varian_ditemukan) {
        cout << "Varian sarung tidak ditemukan." << endl;
    }
}

void hapusSarung() {
    string merk;
    cout << "Masukkan merk sarung yang ingin dihapus : ";
    cin >> merk;

    for (auto it = daftarSarung.begin(); it != daftarSarung.end(); ++it) {
        if ((*it)->merk == merk) { // Dereference pointer
            Sarung* sarungToDelete = *it;
            daftarSarung.erase(it);
            delete sarungToDelete; // Hapus alokasi dinamis
            cout << "Sarung dengan merk " << merk << " berhasil dihapus." << endl;
            return;
        }
    }

    cout << "Merk sarung tidak ditemukan." << endl;
}

int main() {
    cout << "Selamat datang di toko sarung" << endl;
    // Melakukan login
    if (!login()) {
        cout << " " << endl;
        return 1;
    }

    string masukan_pilihan;
    vector<Sarung*> daftarSarungKloning; // Salinan sementara dari vektor daftarSarung

    while (true) {
        cout << "1. Tampilkan semua jenis sarung" << endl;
        cout << "2. Tambahkan jenis varian sarung" << endl;
        cout << "3. Update jenis varian sarung" << endl;
        cout << "4. Hapus jenis varian sarung" << endl;
        cout << "5. Cari jenis varian sarung secara ascending(huruf)" << endl;
        cout << "6. Cari jenis varian sarung secara descending(huruf)" << endl;
        cout << "7. Urutkan varian sarung dengan Bubble Sort (Descending-huruf)" << endl;
        cout << "8. Urutkan harga varian sarung dengan Quick Sort (Ascending-angka)" << endl;
        cout << "9. Urutkan harga varian sarung dengan Selection Sort" << endl;
        cout << "10. Keluar" << endl;
        cout << "Masukkan pilihan anda : ";
        cin >> masukan_pilihan;

        if (masukan_pilihan == "1") {
            tampilkanSarung(daftarSarungKloning.empty() ? daftarSarung : daftarSarungKloning);
        } else if (masukan_pilihan == "2") {
            tambahSarung();
            // Perbarui daftarSarungKloning setelah penambahan data
            daftarSarungKloning = daftarSarung;
        } else if (masukan_pilihan == "3") {
            string merk;
            cout << "Pilih merk sarung yang ingin diupdate : ";
            cin >> merk;

            bool found = false;
            for (auto& sarungPtr : daftarSarung) {
                if (sarungPtr->merk == merk) {
                    updateSarung(sarungPtr); // Parameter address-of
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Merk sarung tidak ditemukan." << endl;
            }

            // Perbarui daftarSarungKloning setelah update data
            daftarSarungKloning = daftarSarung;
        } else if (masukan_pilihan == "4") {
            hapusSarung();
            // Perbarui daftarSarungKloning setelah penghapusan data
            daftarSarungKloning = daftarSarung;
        } else if (masukan_pilihan == "5") {
            string keyword;
            cout << "Masukkan kata kunci untuk pencarian secara ascending: ";
            cin >> keyword;
            vector<Sarung*> hasilPencarian = cariSarungAscending(keyword);
            tampilkanSarung(hasilPencarian);
        } else if (masukan_pilihan == "6") {
            string keyword;
            cout << "Masukkan kata kunci untuk pencarian secara descending: ";
            cin >> keyword;
            vector<Sarung*> hasilPencarian = cariSarungDescending(keyword);
            tampilkanSarung(hasilPencarian);
        } else if (masukan_pilihan == "7") {
            vector<string> varian;
            for (const auto& sarungPtr : daftarSarung) {
                for (int j = 0; j < sarungPtr->jumlahVarian; ++j) {
                    varian.push_back(sarungPtr->varian[j]);
                }
            }
            bubbleSortDescending(varian);
            for (const auto& v : varian) {
                cout << v << endl;
            }
        } else if (masukan_pilihan == "8") {
            vector<int> harga;
            for (const auto& sarungPtr : daftarSarung) {
                for (int j = 0; j < sarungPtr->jumlahVarian; ++j) {
                    harga.push_back(sarungPtr->harga[j]);
                }
            }
            quickSortAscending(harga, 0, harga.size() - 1);
            for (const auto& h : harga) {
                cout << "Rp : " << h << endl;
            }
        } else if (masukan_pilihan == "9") {
            vector<int> harga;
            for (const auto& sarungPtr : daftarSarung) {
                for (int j = 0; j < sarungPtr->jumlahVarian; ++j) {
                    harga.push_back(sarungPtr->harga[j]);
                }
            }
            selectionSort(harga);
            for (const auto& h : harga) {
                cout << "Rp : " << h << endl;
            }
        } else if (masukan_pilihan == "10") {
            cout << "Terima kasih telah menggunakan program ini." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid, silahkan coba lagi." << endl;
        }
    }

    // Menghapus semua alokasi dinamis sebelum keluar dari program
    for (auto& sarungPtr : daftarSarung) {
        delete sarungPtr;
    }

    return 0;
}
