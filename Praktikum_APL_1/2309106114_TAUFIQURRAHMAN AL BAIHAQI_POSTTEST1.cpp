#include <iostream>
using namespace std;

int main(){
        string nama;
    string nim;
    int trylogin = 0;

    while (trylogin < 3){
    

        cout << "silahkan masukan nama anda : ";
        cin >> nama;
        cout << "silakan masukan nim anda : ";
        cin >> nim;
        
        if (nama == "opick" && nim == "2309106114")
        {
            cout << "anda berhasil login" << endl;
            while(true) {
                string pilihan;
                double celcius, reamur, fahrenheit, kelvin;

                cout << "pilihanlah suhu yang ingin di konverensikan" << endl;
                cout << "1.celcius" << endl;
                cout << "2.kelvin" << endl;
                cout << "3.reamur" << endl;
                cout << "4.fahrenheit" << endl;
                cout << "5.berhenti" << endl;
                cout << "silahkan masukan no pilihanan anda :" << endl;
                cin >> pilihan;

                if(pilihan == "1"){
                    cout << "Masukkan suhu celcius yang akan dikonversikan : " << endl;
                    cin >> celcius;
                    kelvin = celcius + 273;
                    reamur = celcius * 4 / 5;
                    fahrenheit = (celcius * 9 / 5) + 32;
                    cout << celcius << " Celcius = " << kelvin << " Derajat Kelvin" << endl;
                    cout << celcius << " Celcius = " << reamur << " Derajat Reamur" << endl;
                    cout << celcius << " Celcius = " << fahrenheit << " Derajat Fahrenheit" << endl;
                } else if(pilihan == "2"){
                    cout << "Masukkan suhu kelvin yang akan dikonversikan : " << endl;
                    cin >> kelvin;
                    celcius = kelvin - 273;
                    reamur = (kelvin - 273 ) * 4 / 5;
                    fahrenheit = (kelvin - 273) * 9 / 5 + 32;
                    cout << kelvin << " Kelvin = " << celcius << " Derajat Celcius" << endl;
                    cout << kelvin << " Kelvin = " << reamur << " Derajat Reamur" << endl;
                    cout << kelvin << " Kelvin = " << fahrenheit << " Derajat Fahrenheit" << endl;
                } else if(pilihan == "3"){
                    cout << "Masukkan suhu reamur yang akan dikonversikan : " << endl;
                    cin >> reamur;
                    celcius = reamur * 5 / 4;
                    kelvin = reamur * 5 / 4 + 32;
                    fahrenheit = reamur * 9 / 4 + 32;
                    cout << reamur << " Reamur = " << celcius << " Derajat Celcius" << endl;
                    cout << reamur << " Reamur = " << kelvin << " Derajat Kelvin" << endl;
                    cout << reamur << " Reamur = " << fahrenheit << " Derajat Fahrenheit" << endl;
                } else if (pilihan == "4") {
                    cout << "Masukkan suhu fahrenheit yang akan dikonversikan : " << endl;
                    cin >> fahrenheit;
                    celcius = (fahrenheit - 32) * 5 / 9;
                    reamur = (fahrenheit - 32) * 4 / 9;
                    kelvin = (fahrenheit - 32) * 5 / 9 + 273;
                    cout << fahrenheit << " Fahrenheit = " << celcius << " Derajat Celcius" << endl;
                    cout << fahrenheit << " Fahrenheit = " << reamur << " Derajat Reamur" << endl;
                    cout << fahrenheit << " Fahrenheit = " << kelvin << " Derajat Kelvin" << endl;
                 } else if (pilihan == "5") {
                    cout << "Terima kasih telah menggunakan program ini." << endl;
                    break; 
                } else {
                    cout << "Nomor tersebut tidak tersedia" << endl;
                }
             }
            break;
        } else {
            cout << "Login gagal. Silakan coba lagi." << endl;
            trylogin++;
        }
    }

    if (trylogin >= 3) {
        cout << "Anda sudah mencoba login sebanyak 3 kali. Program berhenti." << endl;
    }

    return 0;
}