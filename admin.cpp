#include <iostream>
#include <string>
using namespace std;

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

const int jumlah_max_buku = 3000;
int jumlahBuku = 3;
Buku daftarBuku[jumlah_max_buku] = {
    {1, "To Kill a Mockingbird", "Harper Lee", "J.B. Lippincott & Co.", 1960, "A novel about racial injustice in the Deep South.", "978-0-06-112008-4", "Fiction", 281},
    {2, "1984", "George Orwell", "Secker & Warburg", 1949, "A dystopian social science fiction novel.", "978-0-452-28423-4", "Dystopian", 328},
    {3, "The Great Gatsby", "F. Scott Fitzgerald", "Charles Scribner's Sons", 1925, "A novel about the American dream and its pitfalls.", "978-0-7432-7356-5", "Fiction", 180},
};

void tambahBuku(int jumlah) 
{
    if (jumlah == 0 || jumlahBuku >= jumlah_max_buku) 
    {
        return;
    }
    cout << "MASUKKAN DATA BUKU KE- " << jumlahBuku + 1 << endl;
    cout << "ID Buku         : "; cin >> daftarBuku[jumlahBuku].IDBuku;
    cout << "Judul Buku      : "; cin.ignore(); getline(cin, daftarBuku[jumlahBuku].judulBuku);
    cout << "Penulis Buku    : "; getline(cin, daftarBuku[jumlahBuku].penulisBuku);
    cout << "Penerbit Buku   : "; getline(cin, daftarBuku[jumlahBuku].penerbitBuku);
    cout << "Tahun Terbit    : "; cin >> daftarBuku[jumlahBuku].tahunTerbit;
    cin.ignore();
    cout << "Sinopsis Buku   : "; getline(cin, daftarBuku[jumlahBuku].sinopsisBuku);
    cout << "ISBN            : "; getline(cin, daftarBuku[jumlahBuku].ISBNBuku);
    cout << "Genre Buku      : "; getline(cin, daftarBuku[jumlahBuku].genreBuku);
    cout << "Jumlah Halaman  : "; cin >> daftarBuku[jumlahBuku].jumlahHalamanBuku;
    cout << endl;
    
    jumlahBuku++;
    cout << "Buku berhasil ditambahkan!" << endl;
    tambahBuku(jumlah - 1);
}

void cekBukuRekursif(int index) 
{
    if (index >= jumlahBuku) 
    {
        return;
    }
    cout << "ID Buku         : " << daftarBuku[index].IDBuku << endl;
    cout << "Judul Buku      : " << daftarBuku[index].judulBuku << endl;
    cout << "Penulis Buku    : " << daftarBuku[index].penulisBuku << endl;
    cout << "Penerbit Buku   : " << daftarBuku[index].penerbitBuku << endl;
    cout << "Tahun Terbit    : " << daftarBuku[index].tahunTerbit << endl;
    cout << "Sinopsis Buku   : " << daftarBuku[index].sinopsisBuku << endl;
    cout << "ISBN            : " << daftarBuku[index].ISBNBuku << endl;
    cout << "Genre Buku      : " << daftarBuku[index].genreBuku << endl;
    cout << "Jumlah Halaman  : " << daftarBuku[index].jumlahHalamanBuku << endl;
    cout << endl;
    cekBukuRekursif(index + 1);
}

void cekSemuaBuku() {
    if (jumlahBuku == 0) {
        cout << "Tidak ada buku dalam daftar." << endl;
        return;
    }
    cout << "Daftar Buku:" << endl;
    cekBukuRekursif(0);
}

void cariBuku() {
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
                if (daftarBuku[i].IDBuku == id) {
                    cout << endl;
                    cout << "ID Buku         : " << daftarBuku[i].IDBuku << endl;
                    cout << "Judul Buku      : " << daftarBuku[i].judulBuku << endl;
                    cout << "Penulis Buku    : " << daftarBuku[i].penulisBuku << endl;
                    cout << "Penerbit Buku   : " << daftarBuku[i].penerbitBuku << endl;
                    cout << "Tahun Terbit    : " << daftarBuku[i].tahunTerbit << endl;
                    cout << "Sinopsis Buku   : " << daftarBuku[i].sinopsisBuku << endl;
                    cout << "ISBN            : " << daftarBuku[i].ISBNBuku << endl;
                    cout << "Genre Buku      : " << daftarBuku[i].genreBuku << endl;
                    cout << "Jumlah Halaman  : " << daftarBuku[i].jumlahHalamanBuku << endl;
                    cout << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "Buku dengan ID \"" << id << "\" tidak ditemukan." << endl;
            }
            break;
        }
        case 2: {
            string judul;
            cout << "Masukkan Judul Buku: "; getline(cin, judul);
            bool found = false;
            for (int i = 0; i < jumlahBuku; i++) {
                if (daftarBuku[i].judulBuku == judul) {
                    cout << "ID Buku         : " << daftarBuku[i].IDBuku << endl;
                    cout << "Judul Buku      : " << daftarBuku[i].judulBuku << endl;
                    cout << "Penulis Buku    : " << daftarBuku[i].penulisBuku << endl;
                    cout << "Penerbit Buku   : " << daftarBuku[i].penerbitBuku << endl;
                    cout << "Tahun Terbit    : " << daftarBuku[i].tahunTerbit << endl;
                    cout << "Sinopsis Buku   : " << daftarBuku[i].sinopsisBuku << endl;
                    cout << "ISBN            : " << daftarBuku[i].ISBNBuku << endl;
                    cout << "Genre Buku      : " << daftarBuku[i].genreBuku << endl;
                    cout << "Jumlah Halaman  : " << daftarBuku[i].jumlahHalamanBuku << endl;
                    cout << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "Buku dengan judul \"" << judul << "\" tidak ditemukan." << endl;
            }
            break;
        }
        default:
            cout << "Pilihan tidak valid!" << endl;
    }
}

void menuAdmin() {
    system("cls");
    int pilihan;
    do {
        cout << "\n=== MENU ADMIN ===" << endl;
        cout << "[1] Tambah Daftar Buku" << endl;
        cout << "[2] Cek Semua Buku" << endl;
        cout << "[3] Cari Buku" << endl;
        cout << "[4] Hapus Buku" << endl;
        cout << "[5] Logout" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1: 
            int jumlah;
            system("cls");
            cout << "Masukkan jumlah buku yang ingin ditambahkan: "; 
            cin >> jumlah;
            tambahBuku(jumlah);
            break;

            case 2:
            cekSemuaBuku();
            break;

            case 3:
            cariBuku();
            break;

            case 4:
            break;

            case 5: 
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
