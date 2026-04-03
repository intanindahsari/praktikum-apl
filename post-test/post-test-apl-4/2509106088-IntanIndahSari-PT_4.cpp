#include <iostream>
#include <iomanip>
using namespace std;


struct Login{
    string username = "Intan";
    string password = "088";
};

struct Register{
    string usernameregis;
    string passwordregis;
};

struct LoginUser{
    int id_user = 0;
    Register regis;
};

struct RankingMusik{
    int posisi;
    string judulLagu;
    string genre;
};

bool Registrasi (string usernameregis, string &passwordregis, int &jumlahUser, LoginUser user[], int &id_user){

    for (int i= 0; i < jumlahUser; i++){
        if (usernameregis == user[i].regis.usernameregis){
            cout <<"Username sudah terdaftar\n";
            cout <<"silahkan pakai username yang lain\n";
            return false;
        }
    }
    if (usernameregis == "Intan"){
        cout <<"Username sudah terdaftar\n";
        cout <<"silahkan pakai username yang lain\n";
        return false;
    }
    else {
        user[jumlahUser].regis.usernameregis = usernameregis;
        user[jumlahUser].regis.passwordregis = passwordregis;
        user[jumlahUser].id_user = jumlahUser + 1;
        jumlahUser++;
        return true;
    }
}
void RegisterUser (string &usernameregis, string &passwordregis, int &jumlahUser, LoginUser user[], int &id_user){
    cout <<"Masukan USERNAME: "; getline (cin, usernameregis);
    cout <<"Masukan PASSWORD: "; getline (cin, passwordregis);
    if (Registrasi(usernameregis, passwordregis, jumlahUser, user, id_user)){
        cout << "Registrasi Berhasil ✅\n";
    }
}
int login_User_Admin(int &jumlahUser, Login admin ,LoginUser user[], int &id_user, string &inputname, string &inputpass, int &loginawal){
    if(inputname == admin.username && inputpass == admin.password){
        return 1;
    }
    for  (int i = 0; i < jumlahUser; i++){
        if (inputname == user[i].regis.usernameregis && inputpass == user[i].regis.passwordregis){
            id_user = user[i].id_user;
            return 2;
        }
    }
    loginawal++;
    if (loginawal >= 3){
        cout <<"Anda telah melakukan login sebanyak 3 kali\n";
        return 4;
    }
    return 3;
}
void Lihat_BlindRanking(int &n, RankingMusik musik[]) {
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
void Tambah_RankingMusik(int *n, RankingMusik musik[] ) {
    cout << "===============================================\n";
    cout << "TAMBAH RANKING MUSIK\n";
    cout << "===============================================\n";
    cout << "Masukan Judul lagu: " << endl;
    getline (cin, musik[*n].judulLagu);
    cout << "----------------------------------------------\n";
    cout << "Masukan Genre lagu: " << endl;
    getline (cin, musik[*n].genre);
    cout << "----------------------------------------------\n";
    cout << "Data berhasil ditambahkan✅\n";
    (*n)++;
    musik[*n - 1].posisi = *n;
}
void Update_RankingMusik(int *n, RankingMusik musik[], int updateposisi) {
    cout << "===============================================\n";
    cout << "UPDATE RANKING MUSIK\n";
    cout << "===============================================\n";
    cout << "Masukan No lagu yang ingin di update: "; cin >> updateposisi;
    cout << "-----------------------------------------------\n";
    cin.ignore();
    if (updateposisi > 0 && updateposisi <= *n ){
        cout << "Masukan judul lagu yang ingin di update: "; getline (cin, musik[updateposisi - 1].judulLagu);
        cout << "-----------------------------------------------\n";
        cout << "Masukan genre lagu yang ingin di update: "; getline (cin, musik[updateposisi - 1].genre);
        cout << "-----------------------------------------------\n";
        cout << "Data berhasil diupdate✅\n";
    }
}
void Hapus_RankingMusik(int *n, RankingMusik musik[],  int hapusposisi) {
    cout << "===============================================\n";
    cout << "HAPUS RANKING MUSIK\n";
    cout << "===============================================\n";
    cout << "Masukan No lagu yang ingin dihapus: "; cin >> hapusposisi;
    cout << "-----------------------------------------------\n";
    if (hapusposisi > 0 && hapusposisi <= *n ){
        for (int i = hapusposisi - 1; i < *n - 1; i++){
            musik[i] = musik[i + 1];
            musik[i].posisi = i + 1;
        }
        (*n)--;
        cout << "Data berhasil dihapus✅\n";
    }
}
void Tambah_TOPSONG(int pilihanTopSong, int *Topsong, int *n, RankingMusik musik[], RankingMusik topsong[]) {
    if (*Topsong < 5){
        cout << "===============================================\n";
        cout << "Tambah TOP SONG" << endl;
        cout << "===============================================\n";
        cout << "Masukan nomor/posisi lagu yang ingin di tambahkan ke my top song"  << endl;
        cin >> pilihanTopSong;
        cout << "---------------------------------------------------\n";
        if (pilihanTopSong > 0 && pilihanTopSong <= *n){
            topsong[*Topsong].judulLagu = musik[pilihanTopSong - 1].judulLagu;
            topsong[*Topsong].genre = musik[pilihanTopSong - 1].genre;
            topsong[*Topsong].posisi = *Topsong + 1;
            (*Topsong)++;
            cout << "-----------------------------------------------\n";
            cout << "Data berhasil ditambahkan ke my top song ✅\n";
            cout << "-----------------------------------------------\n";
        }
        else{
            cout << "-----------------------------------------------\n";
            cout << "Nomor/posisi lagu tidak ditemukan" << endl;  
            cout << "-----------------------------------------------\n";
        }
    }
    else {
        cout << "-----------------------------------------------\n";
        cout << "My Top Song sudah penuh hanya bisa mengisi 5 Lagu\n";
        cout << "-----------------------------------------------\n";
    }
}
void Hapus_TOPSONG(int pilihanTopSong, int *Topsong, int *n, RankingMusik musik[], RankingMusik topsong[]) {
    cout << "===============================================\n";
    cout << "Hapus TOP SONG" << endl;
    cout << "===============================================\n";
    cout << "Masukan nomor/posisi lagu yang ingin di hapus dari my top song"  << endl;
    cin >> pilihanTopSong;
    cout << "-----------------------------------------------\n";
    if (pilihanTopSong > 0 && pilihanTopSong <= *Topsong){
        for (int i = pilihanTopSong - 1; i < *Topsong - 1; i++){
            topsong[i] = topsong[i + 1];
        }
        (*Topsong)--;
        for (int i = 0; i < *Topsong; i++){
            topsong[i].posisi = i + 1;
        }
        cout << "-----------------------------------------------\n";
        cout << "Data berhasil dihapus dari my top song ✅\n";
        cout << "-----------------------------------------------\n";
    }
    else{
        cout << "-----------------------------------------------\n";
        cout << "Nomor/posisi lagu tidak ditemukan" << endl;
        cout << "-----------------------------------------------\n";
    }
}
void Lihat_TOPSONG(int pilihanTopSong, int &Topsong, int &n, RankingMusik musik[], RankingMusik topsong[]) {
    cout << "===============================================\n";
    cout << "LIHAT TOP SONG" << endl;
    cout << "===============================================\n";
    cout <<"+-----+----------------------------------------------+----------------+\n";
    cout <<"| No  | Judul Lagu                                   | Genre          |\n";
    cout <<"+-----+----------------------------------------------+----------------+\n";
    for (int i = 0; i < Topsong; i++){
        cout <<"| " << left << setw (3) << topsong[i].posisi;
        cout << " | " << left << setw(44) << topsong[i].judulLagu;
        cout << " | " << left << setw(14) << topsong[i].genre << " |\n";
    }
    cout <<"+-----+----------------------------------------------+----------------+\n";
}

void cariLagu(int &n, RankingMusik musik[]){
    string cariJudul;
    cout << "===============================================\n";
    cout <<"CARI LAGU DI RANKING MUSIK\n";
    cout << "===============================================\n";
    cout << "Masukan judul lagu yang ingin dicari: "; getline (cin, cariJudul);
    bool ditemukan = false;
    for (int i = 0; i < n; i++){
        RankingMusik *Ptr = &musik[i];
        if (Ptr -> judulLagu == cariJudul ){
            cout << "Lagu ditemukan di posisi " << musik[i].posisi << " dengan alamat memori =  " << Ptr << endl;
            cout << "---------------------------------------------------\n";
            ditemukan = true;
            break;
        }
    }
    if (ditemukan == false){
        cout << "Lagu tidak ditemukan di ranking musik\n";
        cout << "-----------------------------------------------\n";
    }
}
int main(){
    Login admin;
    LoginUser user[100];
    int jumlahUser = 0;
    int id_user = 0;
    string inputname, inputpass, namebaru, passbaru;
    string usernameregis, passwordregis, username, password;
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

    int n = 10;
    int pilihMenu, pilih, pilihanTopSong;
    RankingMusik topsong[5];
    int Topsong = 0;
    cout <<"===============================================\n";
    cout <<"                   Menu Awal                   \n";
    cout <<"===============================================\n";
    while (true){
        cout <<"1. Login\n";
        cout <<"2. Registrasi\n";
        cout <<"3. Keluar\n";
        cout <<"Masukan pilihan menu: \n"; cin >> pilihMenu;
        cin.ignore();
        if (pilihMenu == 1){
            int loginawal = 0;
            while (loginawal < 3){
                cout <<"Masukan USERNAME: "; getline (cin, inputname);
                cout <<"Masukan PASSWORD: "; getline (cin, inputpass);
                int Kategori = login_User_Admin(jumlahUser, admin, user, id_user, inputname, inputpass, loginawal);
                if (Kategori == 1) {
                    cout <<"Login sebagai ADMIN\n";
                    cout <<"               Selamat Datang, " << admin.username << " \n";
                    while(true){
                        cout <<"===============================================\n";
                        cout <<"                   Menu ADMIN                  \n";
                        cout <<"===============================================\n";
                        cout <<"1. Lihat Blind Ranking Musik\n";
                        cout <<"2. Tambah Ranking Musik\n";
                        cout <<"3. Update Ranking Musik\n";
                        cout <<"4. Hapus Ranking Musik\n";
                        cout <<"5. Keluar\n";
                        cout <<"Masukan angka pilihanmu: \n"; cin >> pilih;
                        cin.ignore();
                        if (pilih == 1) {
                            Lihat_BlindRanking( n, musik);
                        }
                        else if (pilih == 2) {
                            Tambah_RankingMusik( &n, musik);
                        }
                        else if (pilih == 3) {
                            Update_RankingMusik(&n, musik, 0);
                        }
                        else if (pilih == 4) {
                            Hapus_RankingMusik(&n, musik, 0);
                        }
                        else if (pilih == 5) {
                            cout <<"Terima kasih telah menggunakan program ini\n";
                            cout <<"===============================================\n";
                            break;
                        }
                        else {
                            cout << "Pilihan menu tidak tersedia\n";
                        }
                    }
                    break;
                }
                else if (Kategori == 2){
                    loginawal = 0;
                    cout <<"Login sebagai USER\n";
                    cout <<"               Selamat Datang, " << inputname << " \n";
                    cout <<"===============================================\n";
                    cout <<"                   Menu USER                   \n";
                    cout <<"===============================================\n";
                    cout <<"                   ID_ USER: " << id_user << endl;
                    cout <<"===============================================\n";
                    while(true){
                        cout <<"1. Lihat Blind Ranking Musik\n";
                        cout <<"2. Tambah TOP SONG\n";
                        cout <<"3. Hapus TOP SONG\n";
                        cout <<"4. Lihat TOP SONG\n";
                        cout <<"5. Cari Lagu di Ranking Musik\n";
                        cout <<"6. Keluar\n";
                        cout <<"Masukan angka pilihanmu: \n"; cin >> pilihanTopSong;
                        cin.ignore();
                        if (pilihanTopSong == 1) {
                            Lihat_BlindRanking(n, musik);
                        }
                        else if (pilihanTopSong == 2) {
                            Tambah_TOPSONG(pilihanTopSong, &Topsong, &n, musik, topsong);
                    }
                    else if (pilihanTopSong == 3) {
                        Hapus_TOPSONG(pilihanTopSong, &Topsong, &n, musik, topsong);
                    }
                    else if (pilihanTopSong == 4) {
                        Lihat_TOPSONG(pilihanTopSong, Topsong, n, musik, topsong);
                    }
                    else if (pilihanTopSong == 5) {
                        cariLagu(n, musik);
                    }
                    else if (pilihanTopSong == 6) {
                        cout <<"Terima kasih telah menggunakan program ini\n";
                        cout <<"===============================================\n";
                        break;
                    }
                    else {
                        cout << "Pilihan menu tidak tersedia\n";
                    }
                }
                break;
            }
            else if (Kategori == 4){
                cout <<"Terima kasih telah menggunakan program ini😊\n";
                cout <<"===============================================\n";
                return 0;
            }
            else{
                cout <<"Login Gagal ❌, silahkan coba lagi " << 3 - loginawal << " kali lagi" << endl;
                cout <<"=========================================================\n";
            }
            }
        }
        else if (pilihMenu == 2) {
            string tempatUser, tempatPass;
            RegisterUser(usernameregis, passwordregis, jumlahUser, user, id_user);
        }
        else if (pilihMenu == 3) {
            cout <<"Terima kasih telah menggunakan program ini😊\n";
            cout <<"===============================================\n";
            return 0;
        }
        else {
            cout << "Pilihan menu tidak tersedia\n";
        }
    }
    return 0;
}