#include <iostream>
using namespace std;


int main(){
    system("cls");

    int login_ulang = 0;
    float KiloMeter, CentiMeter, Meter, angka;
    string nim = "088"; 
    string nama = "Intan";
    string jawabanPertanyaan;
    int angkaPilihan, Pilihan;

    while(login_ulang < 3){
        cout << "Masukan Username:\n";
        cin >> nama;
        cout << "Masukan Password:\n";
        cin >> nim;
        if(nama == "Intan" && nim == "088"){
            cout << "Login Berhasil ✅\n";
            cout << "SELAMAT DATANG " << nama; 
        cout << "\n===============================\n";
        cout << "DIPROGRAM KONVERSI SATUAN UKURAN 📏\n";
        cout << "================================\n";
            while (true){
                cout << "Silahkan pilih MENU 🗒️:\n";
                cout << "1. Konversi Ukuran Meter ke dalam (Km dan Cm)\n";
                cout << "2. Konversi Ukuran Kilometer ke dalam (M dan Cm)\n";
                cout << "3. Konversi Ukuran Centimeter ke dalam (Km dan M)\n";
                cout << "4. Keluar\n";
                cout << "Ketik angka pilihanmu pada menu: ", cin >> angkaPilihan;
                if (angkaPilihan == 1){
                    while(true){
                        cout << "Menu 1\n";
                        cout << "==============================================\n";
                        cout << "1. Konversi Ukuran Meter ke dalam (Km dan Cm)\n";
                        cout << "==============================================\n";
                        cout << "Silahkan pilih Menu\n";
                        cout << "1. Konversi meter ke dalam bentuk Km dan Cm\n";
                        cout << "2. Kembali ke menu utama\n";
                        cout << "----------------------------------------------\n";
                        cout << "Ketik angka pilihanmu pada menu: ", cin >> Pilihan;
                        cout << "_______________________________________________\n";
                        if (Pilihan == 1){
                            cout << "Masukan angka yang ingin di konversi ke dalam bentuk Kilometer dan Centimeter: ";
                            cin >> angka;
                            KiloMeter = angka / 1000;
                            CentiMeter = angka * 100;
                            cout << "Hasil dari konversi Meter ke Kilometer adalah 📈: " << KiloMeter << endl;
                            cout << "Hasil dari konversi Meter ke Centimeter adalah 📉: " << CentiMeter << endl;
                            cout << "==============================================\n";
                        }
                        else {
                            cout << "kembali ke menu utama\n";
                            cout << "Apakah anda ingin kembali ke menu utama?\n";
                            cout << "Ya ✅\n";
                            cout << "Tidak ❌\n";
                            cout << "Masukan jawaban anda: ", cin >> jawabanPertanyaan;
                            if (jawabanPertanyaan == "Ya"){
                                cout << "kembali ke menu utama\n";
                                cout << "==============================================\n";
                            break;
                            }
                            else if (jawabanPertanyaan == "Tidak"){
                                cout << "Terima kasih 🐣\n";
                return 0;
                            }
                        }   
                    }
                }
                else if (angkaPilihan == 2){
                    while (true){
                        cout << "Menu 2\n";
                        cout << "==============================================\n";
                        cout << "2. Konversi ukuran Kilometer ke dalam (M dan Cm)\n";
                        cout << "==============================================\n";
                        cout << "Silahkan pilih Menu\n";
                        cout << "1. Konversi Kilometer ke dalam bentuk Meter dan Centimeter\n";
                        cout << "2. Kembali ke menu utama\n";
                        cout << "----------------------------------------------\n";
                        cout << "Ketik angka pilihanmu pada menu: ", cin >> Pilihan;
                        cout << "_______________________________________________\n";
                        if (Pilihan == 1){
                            cout << "Masukan Angka yang ingin di konversi ke dalam bentuk Meter dan Centimeter: ";
                            cin >> angka;
                            Meter = angka * 1000;
                            CentiMeter = angka * 100000;
                            cout << "Hasil dari konversi Kilometer ke Meter adalah 📉: " << Meter << endl;
                            cout << "Hasil dari konversi Kilometer ke Centimeter adalah 📉: " << CentiMeter << endl;
                            cout << "==============================================\n";
                        }
                        else {
                            cout << "kembali ke menu utama\n";
                            cout << "Apakah anda ingin kembali ke menu utama?\n"; 
                            cout << "Ya ✅\n";
                            cout << "Tidak ❌\n";
                            cout << "Masukan jawaban anda: ", cin >> jawabanPertanyaan;
                            if (jawabanPertanyaan == "Ya"){
                                cout << "kembali ke menu utama\n";
                                cout << "==============================================\n";
                                break;
                            }
                            else if (jawabanPertanyaan == "Tidak"){
                                cout << "Terima kasih 🐣\n";
                return 0;
                            }
                        }
                    }
                    
                }
                else if (angkaPilihan == 3){
                    while (true){
                        cout << "Menu 3\n";
                        cout << "==============================================\n";
                        cout << "3. Konversi ukuran Centimeter ke dalam (Km dan M)\n";
                        cout << "==============================================\n";
                        cout << "Silahkan pilih Menu\n";
                        cout << "1. Konversi Centimeter ke dalam bentuk Kilometer dan Meter\n";
                        cout << "2. Kembali ke menu utama\n";
                        cout << "----------------------------------------------\n";
                        cout << "Ketik angka pilihanmu pada menu: ", cin >> Pilihan;
                        cout << "_______________________________________________\n";
                        if (Pilihan == 1){
                            cout << "Masukan Angka yang ingin di konversi ke dalam bentuk Kilometer dan Meter: ";
                            cin >> angka;
                            KiloMeter = angka / 100000;
                            Meter = angka / 100;
                            cout << "Hasil dari konversi Centimeter ke Kilometer adalah 📈: " << KiloMeter << endl;
                            cout << "Hasil dari konversi Centimeter ke Meter adalah 📈: " << Meter << endl;
                            cout << "==============================================\n";
                        }
                        else {
                            cout << "kembali ke menu utama\n";
                            cout << "Apakah anda ingin kembali ke menu utama?\n"; 
                            cout << "Ya ✅\n";
                            cout << "Tidak ❌\n";
                            cout << "Masukan jawaban anda: ", cin >> jawabanPertanyaan;
                            if (jawabanPertanyaan == "Ya"){
                                cout << "kembali ke menu utama\n";
                                cout << "==============================================\n";
                                break;
                            }
                            else if (jawabanPertanyaan == "Tidak"){
                                cout << "Terima kasih 🐣\n";
                return 0;
                            }
                        }
                    }
                }
                else {
                        cout << "Anda Keluar Dari Program\n";
                        cout << "Terima Kasih Telah Menggunakan Program Ini 😊\n";
                return 0;
                    }
        }
    }
    else{
        cout << "Login Gagal ❌\n";
        cout << "Silahkan Coba Lagi\n";
        login_ulang++;
        
    }
    if (login_ulang == 3){
        cout << "Anda Sudah 3 kali gagal, Program Berakhir 😝\n";
    }
}

    return 0;
}

