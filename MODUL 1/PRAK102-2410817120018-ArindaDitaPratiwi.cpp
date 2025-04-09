#include <iostream>
using namespace std;

struct Kendaraan {
    string platNomor, jenis, namaPemilik, alamat, kota;
};

int main() {
    Kendaraan data;
        data.platNomor = "DA1234MK";
        data.jenis = "RUSH";
        data.namaPemilik = "Andika Hartanto";
        data.alamat = "Jl. Kayu Tangi 1";
        data.kota = "Banjarmasin";

    cout << "\nPlat Nomor Kendaraan: " << data.platNomor << endl;
    cout << "Jenis Kendaraan: " << data.jenis << endl;
    cout << "Nama Pemilik: " << data.namaPemilik << endl;
    cout << "Alamat: " << data.alamat << endl;
    cout << "Kota: " << data.kota << "\n" << endl;
    return 0;
}