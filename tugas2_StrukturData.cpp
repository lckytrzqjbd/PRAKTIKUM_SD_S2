#include <iostream>
#include <iomanip> // Untuk merapikan tampilan output

using namespace std;

int main() {
    int n;
    
        
    cout << "=============================\n";
    cout << "---Program Rotasi Matriks---\n";
    cout << "--By. Luckyta Rizqia Jubaedi\n";
    cout << "=============================\n";
    cout << "Masukkan ukuran matriks (n x n): ";
    cin >> n;

    // Deklarasi array 2D sesuai materi
    int matriks[n][n];

    // 1. Mengisi matriks (Input)
    cout << "Masukkan elemen matriks:" << endl;
    for (int baris = 0; baris < n; baris++) {
        for (int kolom = 0; kolom < n; kolom++) {
            cout << "Matriks[" << baris << "][" << kolom << "]: ";
            cin >> matriks[baris][kolom];
        }
    }

    // Tampilan awal
    cout << "\nMatriks Awal:" << endl;
    for (int baris = 0; baris < n; baris++) {
        for (int kolom = 0; kolom < n; kolom++) {
            cout << setw(4) << matriks[baris][kolom];
        }
        cout << endl;
    }

    // 2. PROSES ROTASI IN-PLACE (Tanpa array baru)
    
    // Langkah A: Transpose (Tukar baris jadi kolom)
    // Sesuai konsep: matriks[i][j] ditukar dengan matriks[j][i]
    for (int baris = 0; baris < n; baris++) {
        for (int kolom = baris + 1; kolom < n; kolom++) {
            int temp = matriks[baris][kolom];
            matriks[baris][kolom] = matriks[kolom][baris];
            matriks[kolom][baris] = temp;
        }
    }

    // Langkah B: Reverse setiap baris (Tukar elemen kiri dengan kanan)
    for (int baris = 0; baris < n; baris++) {
        for (int kolom = 0; kolom < n / 2; kolom++) {
            int temp = matriks[baris][kolom];
            matriks[baris][kolom] = matriks[baris][n - 1 - kolom];
            matriks[baris][n - 1 - kolom] = temp;
        }
    }

    // 3. Menampilkan Hasil Rotasi 90 Derajat
    cout << "\nMatriks Setelah Rotasi 90 Derajat (Searah Jarum Jam):" << endl;
    for (int baris = 0; baris < n; baris++) {
        for (int kolom = 0; kolom < n; kolom++) {
            cout << setw(4) << matriks[baris][kolom];
        }
        cout << endl;
    }

    return 0;
}