#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int random(int bil)
{
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize()
{
    srand(time(NULL));
}

void clrscr()
{
    system("cls");
}

int main()
{
    int menu;
    do
    {
        clrscr();
        cout << "Pilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih : ";
        cin >> menu;

        if (menu == 1)
        {
            clrscr();
            int data[100];
            int cari = 20;
            int counter = 0;
            int flag = 0;
            int save;
            randomize();
            printf("generating 100 number . . \n");
            for (int i = 0; i < 100; i++)
            {
                data[i] = random(100) + 1;
                printf("%d ", data[i]);
            }
            printf("\ndone.\n");

            for (int i = 0; i < 100; i++)
            {
                if (data[i] == cari)
                {
                    counter++;
                    flag = 1;
                    save = i;
                }
            }

            if (flag == 1)
            {
                printf("Data ada, sebanyak %d!\n", counter);
                printf("pada indeks ke-%d", save);
            }
            else
            {
                printf("Data tidak ada!\n");
            }

            cin.ignore();
            cin.get();
        }
        else if (menu == 2)
        {
            int n, kiri, kanan, tengah, temp, key;
            bool ketemu = false;

            cout << "Masukkan jumlah data: ";
            cin >> n;
            int angka[n];
            for (int i = 0; i < n; i++)
            {
                cout << "Angka ke-[" << i << "] : ";
                cin >> angka[i];
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    if (angka[j] > angka[j + 1])
                    {
                        temp = angka[j];
                        angka[j] = angka[j + 1];
                        angka[j + 1] = temp;
                    }
                }
            }

            cout << "===============================================================================\n";
            cout << "Data yang telah diurutkan adalah:\n";
            for (int i = 0; i < n; i++)
            {
                cout << angka[i] << " ";
            }

            cout << "\n===============================================================================\n";
            cout << "Masukan angka yang dicari: ";
            cin >> key;

            kiri = 0;
            kanan = n - 1;
            while (kiri <= kanan)
            {
                tengah = (kiri + kanan) / 2;
                if (key == angka[tengah])
                {
                    ketemu = true;
                    break;
                }
                else if (key < angka[tengah])
                {
                    kanan = tengah - 1;
                }
                else
                {
                    kiri = tengah + 1;
                }
            }
            if (ketemu == true)
            {
                cout << "Angka ditemukan! ";
            }
            else
                cout << "Angka tidak ditemukan!";

            cin.ignore();
            cin.get();
        }
        else if (menu == 3)
        {
            cout << "\nPerbedaan antara Sequential Seacrh dan Binary Search\n";
            cout << "Sequential Search dan Binary Search adalah dua metode pencarian data dalam struktur seperti array. Sequential Search bekerja dengan memeriksa setiap elemen satu per satu, dimulai dari indeks pertama hingga terakhir, hingga data yang dicari ditemukan atau seluruh data telah diperiksa. Sementara itu, Binary Search melakukan pencarian dengan membagi ruang pencarian menjadi dua bagian. Algoritma ini hanya dapat digunakan jika data sudah dalam keadaan terurut, jika belum maka data harus diurutkan terlebih dahulu. Prosesnya dimulai dengan membandingkan data yang dicari dengan elemen tengah; jika tidak cocok, algoritma akan memilih setengah bagian array yang relevan dan mengulangi proses tersebut hingga data ditemukan atau ruang pencarian habis.\n";
            cout << "\nKelebihan dan kekurangan Sequential Search\n";
            cout << "Kelebihan utama dari metode ini adalah kemudahannya dalam menemukan data jika posisi data yang dicari berada di awal. Selain itu, teknik ini mudah diimplementasikan dan tidak memerlukan data yang terurut. Namun, Sequential Search juga memiliki beberapa kekurangan. Jika data yang dicari terletak di bagian akhir array, maka waktu pencarian akan menjadi lebih lama karena harus melewati seluruh elemen sebelumnya. Selain itu, jika jumlah data sangat banyak, pencarian dengan metode ini dapat menambah beban pada komputer dan menjadi kurang efisien.\n\n";
            cout << "Kelebihan dan kekurangan Binary Search\n";
            cout << "Binary Search memiliki keunggulan utama pada efisiensi waktu pencarian. Hal ini disebabkan oleh kompleksitas algoritmanya yang lebih rendah dibandingkan Sequential Search, yaitu O(log n). Dengan demikian, Binary Search mampu menemukan data dalam waktu yang jauh lebih singkat, terutama pada dataset berukuran besar. Namun, kelemahan dari Binary Search adalah bahwa metode ini hanya dapat digunakan jika data sudah dalam keadaan terurut. Jika data belum diurutkan, maka perlu dilakukan proses sorting terlebih dahulu sebelum pencarian, yang bisa menjadi beban tambahan dalam implementasi.\n";

            cin.ignore();
            cin.get();
        }

        if (menu == 4) {
            cout << "\nProgram Selesai\n";
            cout << "Program was made by: Arinda Dita Pratiwi (2410817120018)\n\n";
        }

    } while (menu != 4);

    return 0;
}