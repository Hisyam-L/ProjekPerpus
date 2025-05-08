#ifndef databuku_h
#define databuku_h
#include <string>
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

extern Buku daftarBuku[jumlah_max_buku];
extern int jumlahBuku; 
#endif