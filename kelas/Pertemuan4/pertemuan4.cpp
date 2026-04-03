
#include<iostream>
using namespace std;

// struct Address{
//     string kota;
//     string provinsi;
//     string negara;
// };

// int main(){
//     Address address1, address2;
//     address1.kota = "Samarinda";
//     address1.provinsi = "Kalimantan Timur";
//     address1.negara = "Indonesia";

//     address2 = address1;
//     address2.kota = "IKN";

//     cout << address1.kota << endl;
//     cout << address2.kota << endl;
//     return 0;
// }



// int main(){
//     string nama = "Rangga Aryawinata";
//     cout << &nama << " adalah alamatnya " << nama << endl;
//     return 0;
// }

// int main(){
//     string var = "Aku Variabel";
//     string* varPtr = &var;

//     cout << "Hasil dari varPtr (Alamat): " << varPtr << endl;
//     cout << "Hasil dari *varPtr (Nilai): " << *varPtr << endl;
//     cout << endl << "Kesimpulannya varPtr isi nya alamatnya var" << endl;
//     cout << "*varPtr hasilnya value dari var" << endl;
//     cout << endl;
//     cout << "Hasil/value dari var: " << var << endl;
//     cout << "Hasil/value dari alamat var (&var): " << &var << endl;
//     cout << "Hasil/value dari varPtr: " << varPtr << endl;
//     cout << "Hasil/value dari *varPtr: " << *varPtr << endl;
//     return 0;
// }


int main(){
    cout << "Pointer yang menunjuk ke suatu array" << endl;
    int a[5] = {1, 2, 3, 4, 5};
    int (*aPtr)[5] = &a;
    for(int i = 0; i < 5; i++){
        cout << *aPtr << endl;  // Masih cetak alamat (seperti penjelasan sebelumnya)
    }

    cout << "\nPointer yang menunjuk ke arah elemen array" << endl;
    int b[5] = {1, 2, 3, 4, 5};

    // # int *bPtr = b;
    // # for(int i = 0; i < 5; i++){
    // #     cout << "Alamat: " << bPtr << " | Nilai: " << *bPtr << endl;
    // #     bPtr++;
    // # }

    cout << "\nMengakses hanya elemen tertentu" << endl;
    int *ptrB2 = &b[2];

    cout << "Alamat elemen indeks-2 : " << ptrB2 << endl;
    cout << "Nilai elemen indeks-2  : " << *ptrB2 << endl;

    return 0;
}
