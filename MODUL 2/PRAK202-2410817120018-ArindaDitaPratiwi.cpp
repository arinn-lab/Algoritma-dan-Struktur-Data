#include <iostream>
using namespace std;

const int maks = 10;

struct Stack {
    int data[maks];
    int atas;
} Tumpuk;

int kosong() {
    return Tumpuk.atas == -1 ? 1 : 0;
}

int penuh() {
    if (Tumpuk.atas == maks - 1)
        return 1;
    else
        return 0;
}

void input(int data) {
    if (kosong() == 1) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "\nData " << Tumpuk.data[Tumpuk.atas]
             << " Masuk Ke Stack\n";
    } else if (penuh() == 0) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
             << " Masuk Ke Stack\n";
    } else
        cout << "Tumpukan Penuh\n";
}

void hapus() {
    if (kosong() == 0) {
        cout << "Data Teratas Sudah Terambil\n";
        Tumpuk.atas--;
    } else
        cout << "Data Kosong\n";
}

void tampil() {
    if (kosong() == 0) {
        cout << "\nIsi Stack: ";
        for (int i = 0; i <= Tumpuk.atas; i++) {
            cout << Tumpuk.data[i] << " ";
        }
        cout << endl;
    } else {
        cout << "\nStack Kosong\n";
    }
}

int main() {
    Tumpuk.atas = -1; // Initialize stack
    input(5);
    input(10);
    input(15);
    input(20);
    input(25);
    tampil();
    hapus();
    tampil();
    hapus();
    hapus();
    hapus();
    hapus();
    tampil();
    return 0;
}