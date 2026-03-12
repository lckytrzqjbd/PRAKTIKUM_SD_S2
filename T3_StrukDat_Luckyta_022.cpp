#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

    struct Nilai {
        float absen, tugas, uts, uas, akhir;
        char huruf;
    };
    
    struct Mahasiswa {
        string nama;
        string npm;
        Nilai nilai;
    };
    
int main()
{
    Mahasiswa mhs[20];
    int jmlData = 0;
    int pilih;
    string cariNPM;
    bool ditemukan;
    
    do {
        cout << "==================================\n";
        cout << "------Program Data Mahasiswa------\n";
        cout << "==================================\n";
        
        cout << " 1. Input Data Mahasiswa\n";
        cout << " 2. Tampilkan Data Mahasiswa\n";
        cout << " 3. Edit Data Mahasiswa (Berdasarkan NPM)\n";
        cout << " 4. Hapus Data Mahasiswa (Berdasarkan NPM)\n";
        cout << " 5. Exit\n";
        cout << " Pilih Menu (1-5): ";
        cin >> pilih;
        
        switch (pilih) {
            case 1:
                if (jmlData < 20) {
                    cout << "============================================\n";
                    cout << " Masukkan Data ke-" << jmlData + 1 << ": \n";
                    cout << " Nama: ";
                    cin >> mhs[jmlData].nama;
                    cout << " NPM: ";
                    cin >> mhs[jmlData].npm;
                    cout << " Nilai Absen    (10%): ";
                    cin >> mhs[jmlData].nilai.absen;
                    cout << " Nilai Tugas    (20%): ";
                    cin >> mhs[jmlData].nilai.tugas;
                    cout << " Nilai UTS      (30%): ";
                    cin >> mhs[jmlData].nilai.uts;
                    cout << " Nilai UAS      (40%): ";
                    cin >> mhs[jmlData].nilai.uas;
                    
                    mhs[jmlData].nilai.akhir =  (mhs[jmlData].nilai.absen * 0.1)
                                                + (mhs[jmlData].nilai.tugas * 0.2)
                                                + (mhs[jmlData].nilai.uts * 0.3)
                                                + (mhs[jmlData].nilai.uas * 0.4);
                    
                    if (mhs[jmlData].nilai.akhir > 80) mhs[jmlData].nilai.huruf = 'A';
                    else if (mhs[jmlData].nilai.akhir > 70) mhs[jmlData].nilai.huruf = 'B';
                    else if (mhs[jmlData].nilai.akhir > 60) mhs[jmlData].nilai.huruf = 'c';
                    else if (mhs[jmlData].nilai.akhir <= 60) mhs[jmlData].nilai.huruf = 'D';
                
                jmlData++;
                cout << " === Data Berhasil Disimpan! ===\n";
            } else {
                cout << "Penuh! Maksimal 20 Data.";
            }
            break;
            
            case 2:
                cout << "\n================================================================" << endl;
    			cout << left << setw(4)  << "No"
    			     << left << setw(12) << "NPM"
    			     << left << setw(25) << "Nama"
    			     << left << setw(15) << "Nilai Akhir"
    			     << left << "Grade" << endl;
    			cout << "----------------------------------------------------------------" << endl;
    
    			if (jmlData == 0) {
    				cout << "                      --- Data Kosong ---" << endl;
    			} else {
    				for (int i = 0; i < jmlData; i++) {
    					cout << left << setw(4)  << i + 1
    					     << left << setw(12) << mhs[i].npm
    					     << left << setw(25) << mhs[i].nama
    					     << left << setw(15) << fixed << setprecision(1) << mhs[i].nilai.akhir
    					     << left << mhs[i].nilai.huruf << endl;
    				}
    			}
    			cout << "================================================================\n" << endl;
    			break;
    			
			case 3:
    			if (jmlData == 0) {
    			    cout << "==================================" << endl;
    			    cout << "Data Kosong! Masukkan Data Terlebih Dahulu\n";
    			} else {
    			    cout << "Input NPM yang akan di edit: ";
    			    cin >> cariNPM;
    			    ditemukan = false;
    			    for (int i = 0; i < jmlData; i++) {
    			        if (mhs[i].npm == cariNPM) {
    			            cout << "Nama: " << mhs[i].nama << endl;
    			            cout << "Nama Baru: ";
    			            cin.ignore();
    			            getline(cin, mhs[i].nama);
    			            cout << "Nama Sudah Diperbarui!" << endl;
    			            ditemukan = true;
    			        }
    			    }
    			}
    		break;
			
			case 4:
    			if (jmlData == 0) {
    			    cout << "==================================" << endl;
    			    cout << " Data Kosong! Masukkan Data Terlebih Dahulu\n";
    			} else {
    			    cout << " Input NPM Yang Akan Dihapus: ";
    			    cin >> cariNPM;
    			    ditemukan = false;
    			    for (int i = 0; i < jmlData; i++) {
    			        if (mhs[i].npm == cariNPM) {
    			            // Pergeseran array untuk menghapus data
    						for (int j = i; j < jmlData - 1; j++) {
    							mhs[j] = mhs[j + 1];
    						}
    						jmlData--;
    						cout << " Data Berhasil Dihapus!" << endl;
    						ditemukan = true;
    			        }
    			    }
    			    if (!ditemukan) cout << " NPM Tidak Ditemukan!";
    			}
    		break;
    		
			case 5:
    			cout << " Terimakasih! Sampai Jumpa Kembali";
    			break;
    			
			default:
			    cout << " Pilihan Tidak Valid!\n";
        }
    } while (pilih != 5);

    return 0;
}
