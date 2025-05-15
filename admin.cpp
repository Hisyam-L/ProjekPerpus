#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int jumlah_max_buku = 3000;
struct Buku
{
    int IDBuku;
    string judulBuku;
    string penulisBuku;
    string penerbitBuku;
    int tahunTerbit;
    string sinopsisBuku;
    string ISBNBuku;
    string genreBuku;
    int jumlahHalamanBuku;
};

Buku* daftarBuku[jumlah_max_buku];
int jumlahBuku = 120;

void BacaDataFile() 
{
    ifstream file("data_buku.txt");
    if (!file.is_open()) {
        cout << "File tidak ditemukan.\n";
        return;
    }

    while (file.eof() && jumlahBuku < jumlah_max_buku) {
        Buku* buku = new Buku;
        file >> buku->IDBuku;
        file.ignore();
        getline(file, buku->judulBuku);
        getline(file, buku->penulisBuku);
        getline(file, buku->penerbitBuku);
        file >> buku->tahunTerbit;
        file.ignore();
        getline(file, buku->sinopsisBuku);
        getline(file, buku->ISBNBuku);
        getline(file, buku->genreBuku);
        file >> buku->jumlahHalamanBuku;
        file.ignore();

        daftarBuku[jumlahBuku++] = buku;
    }
    file.close();
}

void simpanDataBuku()
{
    ofstream file("data_buku.txt");
    if (!file.is_open()) {
        cout << "Gagal membuka file untuk menyimpan data.\n";
        return;
    }

    for (int i = 0; i < jumlahBuku; i++) {
        file << daftarBuku[i]->IDBuku << endl;
        file << daftarBuku[i]->judulBuku << endl;
        file << daftarBuku[i]->penulisBuku << endl;
        file << daftarBuku[i]->penerbitBuku << endl;
        file << daftarBuku[i]->tahunTerbit << endl;
        file << daftarBuku[i]->sinopsisBuku << endl;
        file << daftarBuku[i]->ISBNBuku << endl;
        file << daftarBuku[i]->genreBuku << endl;
        file << daftarBuku[i]->jumlahHalamanBuku << endl;
    }
    file.close();
}

void tambahDataBuku() 
{
    int jumlahInput;
    system("cls");
    cout << "Berapa buku yang ingin ditambahkan? ";
    cin >> jumlahInput;
    cin.ignore();

    for (int i = 0; i < jumlahInput; i++) {
        if (jumlahBuku >= jumlah_max_buku) {
            cout << "Data penuh. Tidak bisa menambah lebih banyak.\n";
            break;
        }

        cout << "\n--- Input Buku ke-" << jumlahBuku + 1 << " ---\n";
        Buku* buku = new Buku;
        cin.ignore();
        cout << "ID Buku         : "; cin >> buku->IDBuku;
        cout << "Judul Buku      : "; cin.ignore(); getline(cin, buku->judulBuku);
        cout << "Penulis Buku    : "; getline(cin, buku->penulisBuku);
        cout << "Penerbit Buku   : "; getline(cin, buku->penerbitBuku);
        cout << "Tahun Terbit    : "; cin >> buku->tahunTerbit;
        cin.ignore();
        cout << "Sinopsis Buku   : "; getline(cin, buku->sinopsisBuku);
        cout << "ISBN            : "; getline(cin, buku->ISBNBuku);
        cout << "Genre Buku      : "; getline(cin, buku->genreBuku);
        cout << "Jumlah Halaman  : "; cin >> buku->jumlahHalamanBuku;
        cin.ignore();

        daftarBuku[jumlahBuku++] = buku;
        simpanDataBuku();
        cout << "Buku berhasil ditambahkan!" << endl;
    }
}

void hapusBuku() 
{
    if (jumlahBuku == 0) {
        cout << "Tidak ada buku dalam daftar." << endl;
        return;
    }
    int id;
    cout << "Masukkan ID Buku yang ingin dihapus: ";
    cin >> id;

    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i]->IDBuku == id) {
            delete daftarBuku[i];
            for (int j = i; j < jumlahBuku - 1; j++) {
                daftarBuku[j] = daftarBuku[j + 1];
            }
            jumlahBuku--;
            cout << "Buku dengan ID " << id << " berhasil dihapus." << endl;
            return;
        }
    }
    cout << "Buku dengan ID " << id << " tidak ditemukan." << endl;
}

void cariBuku()
{
    if (jumlahBuku == 0) {
        cout << "Tidak ada buku dalam daftar." << endl;
        return;
    }
    
    int pilihan;
    system("cls");
    cout << "Cari Buku Berdasarkan:" << endl;
    cout << "[1] ID Buku" << endl;
    cout << "[2] Judul Buku" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;
    cin.ignore();
    
        switch (pilihan) {
            case 1: {
                int id;
                system("cls");
                cout << "Masukkan ID Buku: ";
                cin >> id;
                cin.ignore();
                bool found = false;
                for (int i = 0; i < jumlahBuku; i++) {
                    if (daftarBuku[i]->IDBuku == id) {
                        cout << "ID Buku         : " << daftarBuku[i]->IDBuku << endl;
                        cout << "Judul Buku      : " << daftarBuku[i]->judulBuku << endl;
                        cout << "Penulis Buku    : " << daftarBuku[i]->penulisBuku << endl;
                        cout << "Penerbit Buku   : " << daftarBuku[i]->penerbitBuku << endl;
                        cout << "Tahun Terbit    : " << daftarBuku[i]->tahunTerbit << endl;
                        cout << "Sinopsis Buku   : " << daftarBuku[i]->sinopsisBuku << endl;
                        cout << "ISBN            : " << daftarBuku[i]->ISBNBuku << endl;
                        cout << "Genre Buku      : " << daftarBuku[i]->genreBuku << endl;
                        cout << "Jumlah Halaman  : " << daftarBuku[i]->jumlahHalamanBuku << endl;
                        found = true;
                        break;
                    {
                }
                if (!found) {
                    cout << "Buku dengan ID \"" << id << "\" tidak ditemukan." << endl;
                }
                break;
            }
            case 2: {
                string judulcari;
                cout << "Masukkan Judul Buku: "; getline(cin, judulcari);
                bool found = false;
                cout << "Hasil pencarian untuk \"" << judulcari << "\":" << endl;
                for (int i = 0; i < jumlahBuku; i++) {
                    if (daftarBuku[i]->judulBuku.find(judulcari) != string::npos) {
                        cout << "ID Buku         : " << daftarBuku[i]->IDBuku << endl;
                        cout << "Judul Buku      : " << daftarBuku[i]->judulBuku << endl;
                        cout << "Penulis Buku    : " << daftarBuku[i]->penulisBuku << endl;
                        cout << "Penerbit Buku   : " << daftarBuku[i]->penerbitBuku << endl;
                        cout << "Tahun Terbit    : " << daftarBuku[i]->tahunTerbit << endl;
                        cout << "Sinopsis Buku   : " << daftarBuku[i]->sinopsisBuku << endl;
                        cout << "ISBN            : " << daftarBuku[i]->ISBNBuku << endl;
                        cout << "Genre Buku      : " << daftarBuku[i]->genreBuku << endl;
                        cout << "Jumlah Halaman  : " << daftarBuku[i]->jumlahHalamanBuku << endl;
                        found = true;
                    }
                }
                if (!found) {
                    cout << "Buku dengan judul \"" << judulcari << "\" tidak ditemukan." << endl;
                }
                break;
            }
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }
}
}

void sortingBukuAbjad() 
{
    for (int i = 0; i < jumlahBuku - 1; i++) {
        for (int j = 0; j < jumlahBuku - i - 1; j++) {
            if (daftarBuku[j]->judulBuku > daftarBuku[j + 1]->judulBuku) {
                Buku* temp = daftarBuku[j];
                daftarBuku[j] = daftarBuku[j + 1];
                daftarBuku[j + 1] = temp;
            }
        }
    }
    cout << endl;
    cout << "Buku berhasil diurutkan berdasarkan huruf awal judul secara alfabetis!" << endl;
    system("pause");
    system("cls");
}

void menuAdmin() {
    system("cls");
    int pilihan;
    do {
        cout << "\n=== MENU ADMIN ===" << endl;
        cout << "[1] Tambah Daftar Buku" << endl;
        cout << "[2] Cari Buku" << endl;
        cout << "[3] Urutkan Buku sesuai Abjad" << endl;
        cout << "[4] Logout" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1: 
            system("cls");
            tambahDataBuku();
            break;

            case 2:
            cariBuku();
            break;

            case 3:
            sortingBukuAbjad();
            break;

            case 4: 
            cout << "Logout berhasil!" << endl; 
            break;

            default: 
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);
}

int main()
{
    menuAdmin();
}
