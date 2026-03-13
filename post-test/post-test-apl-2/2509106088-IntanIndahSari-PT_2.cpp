#include <iostream>
#include <iomanip>
using namespace std;


struct Login {
    string username = "Intan";
    string password = "088";
};

struct Register {
    string usernameregis;
    string passwordregis;
};

struct LoginUser {
    int id_user = 0;
    Register regis;
};

struct RankingMusik {
    int posisi;
    string judulLagu;
    string genre;
};


int main (){
    int pilih, pilihMenuadmin,  pilihMenuuser ,updateposisi, hapusposisi, pilihanTopSong;
    string inputname, inputpass, namebaru, passbaru;
    Login login;
    Register regis;
    LoginUser loginuser [100];
    int jumlahUser = 0;

    RankingMusik musik[100]{
        {1, "XXL", "Pop"},
        {2, "DNA", "Pop"},
        {3, "La La Lost you", "Pop"},
        {4, "The Man Who Can't Be Moved", "Pop Rock"},
        {5, "Out Of  My League", "Pop"},
        {6, "Backburner", "Pop"},
        {7, "We Don't Talk Anymore", "Pop"},
        {8, "Boyfriend", "Pop"},
        {9, "Toxic Till The End", "Pop"},
        {10, "Birds Of A Feather", "Pop"}
    };

    int Topsong = 0;
    RankingMusik topsong[5];
    int n = 10;

    while(true){
        cout << "==============================================\n";
        cout << "                  Menu Awal                   \n";
        cout << "==============================================\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "3. Keluar\n";
        cout << "----------------------------------------------\n";
        cout << "Masukan Pilihan Menu: " ;
        cin >> pilih;
        cin.ignore();

        if (pilih == 1){
            int loginawal = 0;
            while (loginawal < 3){
            cout << "==============================================\n";
            cout << "                     LOGIN                    \n";
            cout << "==============================================\n";
            cout << "Masukan username: "  << endl;
            getline(cin, inputname);
            cout << "----------------------------------------------\n";
            cout << "Masukan password: " << endl;
            cin >> inputpass;
            cin.ignore();
            int i;
                for ( i = 0; i < jumlahUser; i++){
                    if(inputname == loginuser[i].regis.usernameregis && inputpass == loginuser[i].regis.passwordregis ){
                        break;
                    }
                }
                if (inputname == login.username && inputpass == login.password){
                    cout << "----------------------------------------------\n";
                    cout << "               Login Berhasil ✅              \n";
                    cout << "----------------------------------------------\n";
                    cout << "               Selamat Datang  " << login.username << endl;
                    while(true) {
                    cout << "==============================================\n";
                    cout << "     SISTEM MANAJEMEN BLIND RANKING MUSIK     \n";
                    cout << "----------------------------------------------\n";
                    cout << "                   MENU ADMIN                 \n";
                    cout << "==============================================\n";
                    cout << "1. Tambah Ranking Musik\n";
                    cout << "2. Lihat Ranking Musik\n";
                    cout << "3. Update Ranking Musik\n";
                    cout << "4. Hapus Ranking Musik\n";
                    cout << "5. Keluar\n";
                    cout << "===============================================\n";
                    cout << "Masukan Pilihan Menu: \n";
                    cin >> pilihMenuadmin;
                    cin.ignore();
                        if (pilihMenuadmin == 1){
                            cout << "===============================================\n";
                            cout << "TAMBAH RANKING MUSIK\n";
                            cout << "===============================================\n";
                            cout << "Masukan Judul lagu: " << endl;
                            getline (cin, musik[n].judulLagu);
                            cout << "----------------------------------------------\n";
                            cout << "Masukan Genre lagu: " << endl;
                            getline (cin, musik[n].genre);
                            cout << "----------------------------------------------\n";
                            cout << "Data berhasil ditambahkan✅\n";
                            n++;
                            musik[n - 1].posisi = n;      
                        }   
                        else if (pilihMenuadmin == 2){
                            cout << "===============================================\n";
                            cout << "LIHAT RANKING MUSIK\n";
                            cout << "===============================================\n";
                            cout <<"+-----+----------------------------------------------+----------------+\n";
                            cout <<"| No  | Judul Lagu                                   | Genre          |\n";
                            cout <<"+-----+----------------------------------------------+----------------+\n";
                                for (int i = 0; i < n; i++){
                                    cout <<"| " << left << setw (3) << musik[i].posisi;
                                    cout << " | " << left << setw(44) << musik[i].judulLagu;
                                    cout << " | " << left << setw(14) << musik[i].genre << " |\n";
                            }
                            cout <<"+-----+----------------------------------------------+----------------+\n";
                        }
                        else if (pilihMenuadmin == 3){
                            cout << "===============================================\n";
                            cout << "UPDATE RANKING MUSIK\n";
                            cout << "===============================================\n";
                            cout << "Masukan No lagu yang ingin di update: ", cin >> updateposisi;
                            cout << "-----------------------------------------------\n";
                            cin.ignore();
                            if (updateposisi > 0 && updateposisi <= n ){
                                cout << "Masukan judul lagu yang ingin di update: ", getline (cin, musik[updateposisi - 1].judulLagu);
                                cout << "-----------------------------------------------\n";
                                cout << "Masukan genre lagu yang ingin di update: ", getline (cin, musik[updateposisi - 1].genre);
                                cout << "-----------------------------------------------\n";
                                cout << "Data berhasil diupdate✅\n";
                            }
                        }
                        else if (pilihMenuadmin == 4){
                            cout << "===============================================\n";
                            cout << "HAPUS RANKING MUSIK\n";
                            cout << "===============================================\n";
                            cout << "Masukan No lagu yang ingin dihapus: ", cin >> hapusposisi;
                            cin.ignore();
                            cout << "-----------------------------------------------\n";
                            if (hapusposisi > 0 && hapusposisi <= n){
                                for (int i = hapusposisi - 1; i < n - 1; i++){
                                    musik[i] = musik[i + 1];
                                }
                                n--;
                                for (int i = 0; i < n; i++){
                                    musik[i].posisi = i + 1;
                                }
                                cout << "Data berhasil dihapus✅\n";
                            }
                        }
                        else {
                            cout << "Anda Keluar Dari Program Menu Admin\n";
                            break;
                        }
                    }
                    break;
                }
                else if ( i < jumlahUser ){
                    cout << "===============================================\n";
                    cout << "                 Login Berhasil ✅             \n";
                    loginawal = 0;
                    cout << "================================================\n";
                    cout << "               Selamat Datang " << loginuser[i].regis.usernameregis << endl;
                    cout << "-----------------------------------------------\n";
                    cout << "               ID User ke - " << loginuser[i].id_user << endl;
                    while (true){
                    cout << "==============================================\n";
                    cout << "     SISTEM MANAJEMEN BLIND RANKING MUSIK     \n";
                    cout << "----------------------------------------------\n";
                    cout << "                   TOP SONG                   \n";
                    cout << "----------------------------------------------\n";
                    cout << "                   MENU USER                  \n";
                    cout << "==============================================\n";
                    cout << "1. Lihat Ranking Musik\n";
                    cout << "2. Tambah Top Song\n";
                    cout << "3. Hapus Top Song\n";
                    cout << "4. Lihat Top song\n";
                    cout << "5. Keluar\n";
                    cout << "===============================================\n";
                    cout << "Masukan Pilihan Menu: \n";
                    cin >> pilihMenuuser;
                        if (pilihMenuuser == 1){
                            cout << "===============================================\n";
                            cout << "LIHAT RANKING MUSIK\n";
                            cout << "===============================================\n";
                            cout <<"+-----+----------------------------------------------+----------------+\n";
                            cout <<"| No  | Judul Lagu                                   | Genre          |\n";
                            cout <<"+-----+----------------------------------------------+----------------+\n";
                            for (int i = 0; i < n; i++){
                                cout <<"| " << left << setw (3) << musik[i].posisi;
                                cout << " | " << left << setw(44) << musik[i].judulLagu;
                                cout << " | " << left << setw(14) << musik[i].genre << " |\n";
                            }
                            cout <<"+-----+----------------------------------------------+----------------+\n";
                        }
                        else if (pilihMenuuser == 2){
                            if (Topsong < 5){
                                cout << "===============================================\n";
                                cout << "Tambah TOP SONG" << endl;
                                cout << "===============================================\n";
                                cout << "Masukan nomor/posisi lagu yang ingin di tambahkan ke my top song"  << endl;
                                cin >> pilihanTopSong;
                                cout << "---------------------------------------------------\n";
                                if (pilihanTopSong > 0 && pilihanTopSong <= n){
                                    topsong[Topsong].judulLagu = musik[pilihanTopSong - 1].judulLagu;
                                    topsong[Topsong].genre = musik[pilihanTopSong - 1].genre;
                                    topsong[Topsong].posisi = Topsong + 1;
                                    Topsong++;
                                    cout << "-----------------------------------------------\n";
                                    cout << "Data berhasil ditambahkan ke my top song ✅\n";
                                }
                                else{
                                    cout << "-----------------------------------------------\n";
                                    cout << "Nomor/posisi lagu tidak ditemukan" << endl;  
                                }
                            }
                            else {
                                cout << "-----------------------------------------------\n";
                                cout << "My Top Song sudah penuh hanya bisa mengisi 5 Lagu\n";
                            }
                        }
                        else if (pilihMenuuser == 3){
                            cout << "===============================================\n";
                            cout << "Hapus TOP SONG" << endl;
                            cout << "===============================================\n";
                            cout << "Masukan nomor/posisi lagu yang ingin di hapus dari my top song"  << endl;
                            cin >> pilihanTopSong;
                            cout << "-----------------------------------------------\n";
                            if (pilihanTopSong > 0 && pilihanTopSong <= Topsong){
                                for (int i = pilihanTopSong - 1; i < Topsong - 1; i++){
                                    topsong[i] = topsong[i + 1];
                                }
                                Topsong--;
                                for (int i = 0; i < Topsong; i++){
                                    topsong[i].posisi = i + 1;
                                }
                                cout << "-----------------------------------------------\n";
                                cout << "Data berhasil dihapus dari my top song ✅\n";
                            }
                            else{
                                cout << "-----------------------------------------------\n";
                                cout << "Nomor/posisi lagu tidak ditemukan" << endl;
                            }
                        }
                        else if (pilihMenuuser == 4){
                            cout << "===============================================\n";
                            cout << "Lihat daftar TOP SONG" << endl;
                            cout << "===============================================\n";
                            cout <<"+-----+----------------------------------------------+----------------+\n";
                            cout <<"| No  | Judul Lagu                                   | Genre          |\n";
                            cout <<"+-----+----------------------------------------------+----------------+\n";
                            for (int i = 0; i < Topsong; i++){
                                cout <<"| "<< left << setw(3) << topsong[i].posisi;
                                cout << " | " << left << setw(44) << topsong[i].judulLagu;
                                cout << " | " << left << setw(14) << topsong[i].genre << " |\n";
                            }
                            cout <<"+-----+----------------------------------------------+----------------+\n";
                        }
                        else {
                            cout << "Anda Keluar Dari Program Menu User\n";
                            break;
                        }
                    }
                    break;
                }
                else {
                    cout << "===============================================\n";
                    cout << "                  Login Gagal ❌               \n";
                    cout << "===============================================\n";
                    cout << "Silahkan masukan lagi username dan password" << endl;
                    loginawal++;
                }
                if (loginawal == 3){
                    cout << "-----------------------------------------------------\n";
                    cout << "Keluar dari Program Karena sudah 3 kali mencoba login\n";
                    cout << "-----------------------------------------------------\n";
return 0;
                }
            }
        }
        else if (pilih == 2){
            while (true){ 
                cout << "==============================================\n";
                cout << "                    REGISTER                 \n";
                cout << "==============================================\n";
                cout << "Masukan username baru: \n";
                getline(cin, namebaru);
                cout << "----------------------------------------------\n";
                cout << "Masukan password baru: \n";
                cin >> passbaru;
                cin.ignore();
                if (namebaru == login.username){
                    cout <<"-----------------------------------------------\n";
                    cout << "Gagal Registrasi❌\n";
                    cout <<"----------------------------------------------- \n";
                    cout << "Username sudah ada, COBA LAGI\n";
                }
                else {
                    int i;
                    for(i = 0; i < jumlahUser; i++){
                        if (namebaru == loginuser[i].regis.usernameregis){
                            cout << "----------------------------------------------\n";
                            cout << "Gagal Registrasi❌\n";
                            cout << "Username sudah ada\n";
                            cout << "Gunakan Username yang BERBEDA\n";
                            cout << "----------------------------------------------\n";
                            break;
                        }
                    }
                if (i == jumlahUser){
                    loginuser[i].regis.usernameregis = namebaru;
                    loginuser[i].regis.passwordregis = passbaru;
                    loginuser[i].id_user = jumlahUser + 1;
                    jumlahUser++;
                    cout << "----------------------------------------------\n";
                    cout << "Registrasi Berhasil✅\n";
                    }
                }
                break;
                }
            }
            else {
                cout << "Anda Keluar Dari Program\n";
                cout << "Terima Kasih Telah Menggunakan Program Ini 😊\n";
            return 0;
            }
        }
        
        return 0;
    }



