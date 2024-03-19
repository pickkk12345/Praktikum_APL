#include <iostream>
#include <vector>
#include <string>
using namespace std;

string nama = "opick";
string nim = "114";
int trylogin = 0;
int limitlogin = 3;
const int MAX_SARUNG = 100;
string sarung[MAX_SARUNG][10];
int count_sarung = 4;


void tampilkanSarung() {
    for (int i = 0; i < count_sarung; i++) {
        cout << "sarung yang tersedia dari sarung " << sarung[i][0] << " : " << endl;
        for (int j = 1; j < 10 && sarung[i][j] != ""; j++) {
            cout << " - " << sarung[i][j] << endl;
        }
        cout << endl;
    }
}

void tambahSarung() {
    string key, sarung_baru;
    cout << "masukan merek sarung baru : ";
    cin >> key;
    cout << "masukan jenis jenis sarung barunya : ";
    cin.ignore();
    getline(cin, sarung_baru);
    bool found = false;
    for (int i = 0; i < count_sarung; i++) {
        if (sarung[i][0] == key) {
            int j = 1;
            while (j < 10 && sarung[i][j] != "") {
                j++;
            }
            if (j < 10) {
                sarung[i][j] = sarung_baru;
            } else {
                cout << "Jenis sarung sudah mencapai batas maksimum" << endl;
            }
            found = true;
            break;
        }
    }
    if (!found) {
        if (count_sarung < MAX_SARUNG) {
            sarung[count_sarung][0] = key;
            sarung[count_sarung][1] = sarung_baru;
            count_sarung++;
        } else {
            cout << "Jumlah merek sarung sudah mencapai batas maksimum" << endl;
        }
    }
}

void updateSarung() {
    string key, sarung_baru;
    cout << "pilih jenis sarung yang ingin di update : ";
    cin >> key;
    cout << "masukan jenis sarung yang baru : ";
    cin.ignore();
    getline(cin, sarung_baru);
    for (int i = 0; i < count_sarung; i++) {
        if (sarung[i][0] == key) {
            sarung[i][1] = sarung_baru;
            break;
        }
    }
}

void hapusSarung() {
    string key;
    cout << "masukan jenis sarung yang ingin di hapus : ";
    cin >> key;
    for (int i = 0; i < count_sarung; i++) {
        if (sarung[i][0] == key) {
            for (int j = i; j < count_sarung - 1; j++) {
                for (int k = 0; k < 10; k++) {
                    sarung[j][k] = sarung[j + 1][k];
                }
            }
            count_sarung--;
            break;
        }
    }
}

int login(int trylogin = 0){
    string nama = "opick";
    string nim = "114";
    if (trylogin == 3){
        cout << "Login gagal, silahkan coba lagi" << endl;
        return 0;
    }
    string inputnama, inputnim;
    cout << "masukan nama anda : ";
    cin >> inputnama;
    cout << "masukan nim anda : ";
    cin >> inputnim;

    if (inputnama == nama && inputnim == nim) {
        cout << "Login berhasil" << endl;
            string masukan_pilihan;
            while (true) {
                cout << "1.tampilkan semua jenis sarung" << endl;
                cout << "2.tambahkan jenis variant sarung" << endl;
                cout << "3.update jenis variant sarung" << endl;
                cout << "4.hapus jenis variant sarung" << endl;
                cout << "5.Logout" << endl;
                cout << "masukan pilihan anda : ";
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
                    cout << "Anda Telah Logout" << endl;
                    break;
                } else {
                    cout << "pilihan anda tidak tersedia" << endl;
                }
            }
            return 1;
    } else {
        cout << "Login gagal" << endl;
        return login(trylogin + 1); 
    }
}


int main() {

    sarung[0][0] = "sapphire";
    sarung[0][1] = "sapphire motif lilin";
    sarung[0][2] = "sapphire moestro";

    sarung[1][0] = "atlas";
    sarung[1][1] = "atlas 505";
    sarung[1][2] = "atlas junior";
    sarung[1][3] = "atlas jacquard";

    sarung[2][0] = "wadimor";
    sarung[2][1] = "wadimor hujan gerimis gunungan";
    sarung[2][2] = "wadimor relief";
    sarung[2][3] = "wadimor madras";

    sarung[3][0] = "gajah_duduk";
    sarung[3][1] = "gajah duduk marrakesh";
    sarung[3][2] = "gajah duduk maestro";
    sarung[3][3] = "gajah duduk signature";

    cout << "selamat datang di toko sarung" << endl;
    cout << "silahkan login" << endl;
    login();

}

 