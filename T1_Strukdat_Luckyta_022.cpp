#include <iostream>
using namespace std;

int kompresiArray(char huruf[], int size) {
    int j = 0; // sebagai tempat untuk menyimpan hasil kompresi array terbaru

    // perulangan untuk melakukan pengecekan setiap elemen di array untuk dikompresi
    for (int i = 0; i < size; i++) {
        char current = huruf[i]; // Menyimpan huruf pertama disetiap perulangannya
        int hitung = 1; // Jumlah karakter yang muncul dihitung dari 1 karena pada char current, karakter sudah muncul minimal 1

        // Cek apakah huruf ini sudah ada sebelumnya
        bool ada = false;
        for (int k = 0; k < j; k++) {
            if (huruf[k] == current) {
                ada = true;
                break;
            }
        }
        // Jika huruf sebelumnya ada yang sama, maka kode dibawah ini akan dilewati
        if (ada) continue;

        // Hitung berapa kali huruf ini muncul di array (jika 'ada' true, kode perulangan ini akan dilewati)
        for (int k = i + 1; k < size; k++) {
            if (huruf[k] == current) {
                hitung++;
            }
        }

        // Simpan hasil kompresi ke dalam array
        huruf[j++] = current; // Simpan hurufnya
        if (hitung > 1) {
            huruf[j++] = hitung + '0'; // Simpan jumlahnya jika lebih dari 1
        }
    }

    return j; // Mengembalikan panjang array yang sudah dikompresi
}

int main(){
    int size = 5;
    char hurufMutu[size]; // Pendeklarasian array

    cout << "================================" << endl;
    cout << "----- Tugas Kompresi Array -----" << endl;
    cout << "---by Luckyta Rizqia Jubaedi---" << endl;
    cout << "================================" << endl << endl;

    // memasukkan nilai pada array
    for (int i = 0; i < size; i++){
        cout << "Masukkan char ke-"<< i+1 <<" : ";
        cin >> hurufMutu[i];
    }

    // memanggil kompresiArray dan nilai integer dari fungsi disimpan pada variabel integer lengthArray
    int newLength = kompresiArray(hurufMutu, size);

    cout << "output : " << newLength << ", [";
    for (int i = 0; i < newLength; i++){
        cout << "'" << hurufMutu[i] << "'";
        if (i < newLength - 1) {
            cout << ", ";
        }
    }
    cout << "]";

    return 0;
}
