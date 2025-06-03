#include <iostream>

using namespace std;

string nama = "arinda dita pratiwi";
string nim = "2410817120018";

void tukar(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void insertionSort(string &str) {
    for (int i = 1; i < str.size(); i++) {
        char key = str[i];
        int j = i - 1;
        
        while (j >= 0 && str[j] > key) {
            str[j + 1] = str[j];
            j--;
        }
        str[j + 1] = key;
    }
}

void merge(string &str, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    char *tempL = new char[n1];
    char *tempR = new char[n2];
    
    for (int i = 0; i < n1; i++)
        tempL[i] = str[left + i];
    for (int j = 0; j < n2; j++)
        tempR[j] = str[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (tempL[i] <= tempR[j]) {
            str[k] = tempL[i];
            i++;
        } else {
            str[k] = tempR[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        str[k] = tempL[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        str[k] = tempR[j];
        j++;
        k++;
    }
    
    delete[] tempL;
    delete[] tempR;
}

void mergeSort(string &str, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(str, left, mid);
        mergeSort(str, mid + 1, right);
        merge(str, left, mid, right);
    }
}

void shellSort(string &str) {
    int n = str.size();
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = str[i];
            int j;
            for (j = i; j >= gap && str[j - gap] > temp; j -= gap) {
                str[j] = str[j - gap];
            }
            str[j] = temp;
        }
    }
}

int partition(string &str, int low, int high) {
    char pivot = str[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (str[j] <= pivot) {
            i++;
            tukar(str[i], str[j]);
        }
    }
    tukar(str[i + 1], str[high]);
    return (i + 1);
}

void quickSort(string &str, int low, int high) {
    if (low < high) {
        int p_idx = partition(str, low, high);
        quickSort(str, low, p_idx - 1);
        quickSort(str, p_idx + 1, high);
    }
}

void bubbleSort(string &str) {
    int n = str.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                tukar(str[j], str[j + 1]);
            }
        }
    }
}

void selectionSort(string &str) {
    int n = str.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (str[j] < str[minIndex]) {
                minIndex = j;
            }
        }
        tukar(str[i], str[minIndex]);
    }
}

int main() {
    int pilihan;
    string temp;
    
    do {
        cout << "-------------------------------" << endl;
        cout << "|           SORTING           |" << endl;
        cout << "-------------------------------" << endl;
        cout << " 1. Insertion Sort             " << endl;
        cout << " 2. Merge Sort                 " << endl;
        cout << " 3. Shell Sort                 " << endl;
        cout << " 4. Quick Sort                 " << endl;
        cout << " 5. Bubble Sort                " << endl;
        cout << " 6. Selection Sort             " << endl;
        cout << " 7. Keluar                     " << endl;
        cout << "-------------------------------" << endl;
        cout << "Masukkan pilihan : ";
        cin >> pilihan;
        cout << endl;
        
        switch(pilihan) {
            case 1:
                temp = nama;
                cout << "=== INSERTION SORT ===" << endl;
                cout << "Data sebelum diurutkan: " << temp << endl;
                insertionSort(temp);
                cout << "Data setelah diurutkan: " << temp << endl;
                break;
            case 2:
                temp = nama;
                cout << "=== MERGE SORT ===" << endl;
                cout << "Data sebelum diurutkan: " << temp << endl;
                mergeSort(temp, 0, temp.size() - 1);
                cout << "Data setelah diurutkan: " << temp << endl;
                break;
            case 3:
                temp = nama;
                cout << "=== SHELL SORT ===" << endl;
                cout << "Data sebelum diurutkan: " << temp << endl;
                shellSort(temp);
                cout << "Data setelah diurutkan: " << temp << endl;
                break;
            case 4:
                temp = nim;
                cout << "=== QUICK SORT ===" << endl;
                cout << "Data sebelum diurutkan: " << temp << endl;
                quickSort(temp, 0, temp.size() - 1);
                cout << "Data setelah diurutkan: " << temp << endl;
                break;
            case 5:
                temp = nim;
                cout << "=== BUBBLE SORT ===" << endl;
                cout << "Data sebelum diurutkan: " << temp << endl;
                bubbleSort(temp);
                cout << "Data setelah diurutkan: " << temp << endl;
                break;
            case 6:
                temp = nim;
                cout << "=== SELECTION SORT ===" << endl;
                cout << "Data sebelum diurutkan: " << temp << endl;
                selectionSort(temp);
                cout << "Data setelah diurutkan: " << temp << endl;
                break;
            case 7:
                cout << "=== TERIMA KASIH ===" << endl;
                cout << "Program selesai!" << endl;
                cout << "Created by: Arinda Dita Pratiwi (2410817120018)\n" << endl;
                break;
            default:
                cout << "Pilihan tidak valid! Silakan pilih 1-7." << endl;
        }
        
        if (pilihan != 7) {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
            system("cls");
        }
        
    } while (pilihan != 7);
    return 0;
}