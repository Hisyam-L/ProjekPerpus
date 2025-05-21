#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <ctime>
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
    int jumlahsalinan;
};


int jumlah_buku = 100; 
int jumlah_buku_dipinjam = 0; 


struct riwayat_pinjam{
    string judulBuku;
    string username;
    string waktupinjam;
    int idbuku;
};