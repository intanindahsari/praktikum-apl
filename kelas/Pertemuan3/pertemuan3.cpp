#include <iostream>
using namespace std;

void cobaUbahGaji(int gajiSaya) {
gajiSaya = 1000000000; // gaji di dalam prosedur
cout << "Gaji pas di dalam fungsi: " << gajiSaya << endl;
}

void calonJuara() {
// variabel lokal, cuma bisa dipakai di dalam fungsi ini
    calonJuara(); // fungsi berjalan normal
// namun jika kita coba akses Team di sini
// cout << "Tim: " << Team << endl;
// maka akan error karena Team tidak dikenal di sini
string Team = "RRQ";
cout << "Tim: " << Team << endl;
}
int main() {
int gajiSaya = 5000000; // gaji di dalam main

cout << "Gaji awal: " << gajiSaya << endl;

cobaUbahGaji(gajiSaya); // kirim ke fungsi

cout << "Gaji setelah fungsi dipanggil: " << gajiSaya << endl;

return 0;
}





