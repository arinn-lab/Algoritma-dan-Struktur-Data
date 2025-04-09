#include <iostream>
using namespace std;

struct HurufKataAngka {
    char huruf;
    string kata;
    int angka;
};

int main() {
    HurufKataAngka data;
    
    cout << "\nMasukkan sebuah huruf = "; cin >> data.huruf;
    cout << "Masukkan sebuah kata = "; cin >> data.kata;
    cout << "Masukkan Angka = "; cin >> data.angka;
    cout << "\nHuruf yang Anda masukkan adalah " << data.huruf << endl;
    cout << "Kata yang Anda masukkan adalah " << data.kata << endl;
    cout << "Angka yang Anda masukkan adalah " << data.angka << "\n" << endl;
    return 0;
}